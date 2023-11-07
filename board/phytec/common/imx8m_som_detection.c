// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2020 PHYTEC Messtechnik GmbH
 * Author: Teresa Remmet <t.remmet@phytec.de>
 */

#include <common.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/arch/sys_proto.h>
#include <dm/device.h>
#include <dm/uclass.h>
#include <i2c.h>
#include <i2c_eeprom.h>
#include <u-boot/crc.h>

#include "imx8m_som_detection.h"

struct phytec_eeprom_data eeprom_data;

static struct udevice __maybe_unused *phytec_i2c_eeprom_init(char *of_path)
{
	int ret;
	struct udevice *dev;
	ofnode eeprom;

	eeprom = ofnode_path(of_path);
	if (!ofnode_valid(eeprom)) {
		pr_err("%s: Could not find i2c EEPROM in device tree.\n",
		       __func__);
		return NULL;
	}

	ret = uclass_get_device_by_ofnode(UCLASS_I2C_EEPROM, eeprom, &dev);
	if (ret) {
		pr_err("%s: i2c EEPROM not found.\n", __func__);
		return NULL;
	}

	return dev;
}

int phytec_eeprom_data_init(char *of_path, int bus_num, int addr)
{
	int ret, i;
	unsigned int crc;
	u8 som;
	char *opt;
	int *data;

#if defined(CONFIG_DM_I2C)
	struct udevice *dev;

	dev = phytec_i2c_eeprom_init(of_path);
	if (!dev)
		return -ENODEV;

	ret = i2c_eeprom_read(dev, 0, (uint8_t *)&eeprom_data,
			      sizeof(eeprom_data));
#else
	i2c_set_bus_num(bus_num);
	ret =  i2c_read(addr, 0, 2, (uint8_t *)&eeprom_data,
			sizeof(eeprom_data));
#endif
	if (ret) {
		pr_err("%s: Unable to read EEPROM data\n", __func__);
		return ret;
	}

	if (eeprom_data.api_rev == 0xff) {
		pr_err("%s: EEPROM is not flashed. Prototype?\n", __func__);
		return -EINVAL;
	}

	data = (int *)&eeprom_data;
	for (i = 0; i < sizeof(eeprom_data); i += sizeof(data))
		if (*data != 0x0)
			break;

	if (i == sizeof(eeprom_data)) {
		pr_err("%s: EEPROM data is all zero. Erased?\n", __func__);
		return -EINVAL;
	}

	if (eeprom_data.api_rev > PHYTEC_API_REV2) {
		pr_err("%s: EEPROM API revision %u not supported\n",
		       __func__,
		       eeprom_data.api_rev);
		return -EINVAL;
	}

	/* We are done here for early revisions */
	if (eeprom_data.api_rev <= PHYTEC_API_REV1)
		return 0;

	crc = crc8(0, (const unsigned char *)&eeprom_data, sizeof(eeprom_data));
	debug("%s: crc: %x\n", __func__, crc);

	if (crc) {
		pr_err("%s: CRC mismatch. EEPROM data is not usable\n",
		       __func__);
		return -EINVAL;
	}

	som = eeprom_data.data.data_api2.som_no;
	debug("%s: som id: %u\n", __func__, som);
	opt = phytec_get_imx8m_opt();

	if (som == PHYTEC_IMX8MP_SOM && is_imx8mp())
		return 0;

	if (som == PHYTEC_IMX8MM_SOM) {
		if (((opt[0] - '0') != 0) &&
		    ((opt[1] - '0') == 0) && is_imx8mm())
			return 0;
		else if (((opt[0] - '0') == 0) &&
			 ((opt[1] - '0') != 0) && is_imx8mn())
			return 0;
		goto err;
	}

	if (som == PHYTEC_IMX8MQ_SOM && is_imx8mq())
		return 0;
err:
	pr_err("%s: SoM ID does not match. Wrong EEPROM data?\n", __func__);
	return -EINVAL;
}

char * __maybe_unused phytec_get_imx8m_opt(void)
{
	char *opt;

	switch (eeprom_data.api_rev) {
	case PHYTEC_API_REV0:
	case PHYTEC_API_REV1:
		opt = eeprom_data.data.data_api0.opt;
		break;
	case PHYTEC_API_REV2:
		opt = eeprom_data.data.data_api2.opt;
		break;
	default:
		opt = NULL;
		break;
	};

	return opt;
}

/*
 * So far all PHYTEC i.MX8M boards have RAM size definition at the
 * same location.
 */
u8 __maybe_unused phytec_get_imx8m_ddr_size(void)
{
	char *opt;
	u8 ddr_id;

	opt = phytec_get_imx8m_opt();
	if (opt)
		ddr_id = opt[2] - '0';
	else
		ddr_id = 0xff;

	debug("%s: ddr id: %u\n", __func__, ddr_id);
	return ddr_id;
}

/*
 * Filter SPI-NOR flash information. All i.MX8M boards have this at
 * the same location.
 * returns: 0x0 if no SPI is poulated. Otherwise a board depended
 * code for the size. 0xff when the data is invalid.
 */
u8 __maybe_unused phytec_get_imx8m_spi(void)
{
	char *opt;
	u8 spi;

	opt = phytec_get_imx8m_opt();
	if (opt)
		spi = opt[4] - '0';
	else
		spi = 0xff;

	debug("%s: spi: %u\n", __func__, spi);
	return spi;
}

void __maybe_unused phytec_print_som_info(void)
{
	struct phytec_api2_data *api2;
	char pcb_sub_rev;
	unsigned int ksp_no;

	if (eeprom_data.api_rev < PHYTEC_API_REV2)
		return;

	api2 = &eeprom_data.data.data_api2;

	/* Calculate PCB subrevision */
	pcb_sub_rev = api2->pcb_sub_opt_rev & 0x0f;
	pcb_sub_rev = pcb_sub_rev ? ((pcb_sub_rev - 1) + 'a') : 0;

	/* print standard product string */
	if (api2->som_type <= 1) {
		printf("SoM: %s-%03u-%s.%s PCB rev: %u%c\n",
		       phytec_som_type_str[api2->som_type], api2->som_no,
		       api2->opt, api2->bom_rev, api2->pcb_rev, pcb_sub_rev);
		return;
	}
	/* print KSP/KSM string */
	if (api2->som_type <= 3) {
		ksp_no = (api2->ksp_no << 8) | api2->som_no;
		printf("SoM: %s-%u ",
		       phytec_som_type_str[api2->som_type], ksp_no);
	/* print standard product based KSP/KSM strings */
	} else {
		printf("SoM: %s-%03u-%03u ",
		       phytec_som_type_str[api2->som_type],
		       api2->som_no, api2->ksp_no);
	}

	printf("Option: %s BOM rev: %s PCB rev: %u%c\n", api2->opt,
	       api2->bom_rev, api2->pcb_rev, pcb_sub_rev);
}
