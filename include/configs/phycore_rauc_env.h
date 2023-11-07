/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2020 PHYTEC Messtechnik GmbH
 * Author: Martin Schwan <m.schwan@phytec.de>
 */

#ifndef __PHYCORE_RAUC_ENV_H
#define __PHYCORE_RAUC_ENV_H

/*
 * Note:
 *
 * These are environment variables and scripts that help booting an A/B system
 * using RAUC (see https://rauc.io) on PHYTEC's phyCORE SoMs.
 *
 * Implementation:
 *
 *  1. Include this file in your board/SoM configuration.
 *  2. Set the following variables in the U-Boot environment:
 *     a. "doraucboot" for the default value whether to boot the A/B system.
 *     b. "raucdev" the MMC device index that the A/B system is installed on. To
 *        get a list of available MMC devices in U-Boot use "mmc list".
 *  3. Include the macro PHYCORE_RAUC_ENV_BOOTLOGIC environment to add the boot
 *     logic for A/B systems.
 *  4. Make sure CONFIG_BOOTCOMMAND properly boots the A/B system by executing
 *     "run raucboot" depending on the value of "doraucboot".
 *
 * Usage:
 *
 *  1. Set "doraucboot" to "1" to activate booting the A/B system and save this
 *     setting with "saveenv".
 *  2. Run "boot".
 */

#ifdef CONFIG_MX7
#define KERNEL_BOOT_CMD "bootz"
#else
#define KERNEL_BOOT_CMD "booti"
#endif

#define PHYCORE_RAUC_ENV_BOOTLOGIC \
	"raucslot=system0\0" \
	"raucbootpart=1\0" \
	"raucrootpart=2\0" \
	"raucbootpart0=1\0" \
	"raucrootpart0=2\0" \
	"raucbootpart1=3\0" \
	"raucrootpart1=4\0" \
	"raucargs=setenv bootargs console=${console},${baudrate} " \
		"root=/dev/mmcblk${raucdev}p${raucrootpart} " \
		"rauc.slot=${raucslot} rootwait rw\0" \
	"loadraucimage=fatload mmc ${raucdev}:${raucbootpart} ${loadaddr} ${image}\0" \
	"loadraucfdt=fatload mmc ${raucdev}:${raucbootpart} ${fdt_addr} ${fdt_file}\0" \
	"raucemmcboot=echo Booting A/B system from eMMC...; " \
		"if run loadraucimage; then " \
			"if run loadraucfdt; then " \
				"run raucargs; " \
				KERNEL_BOOT_CMD " ${loadaddr} - ${fdt_addr}; " \
			"else " \
				"echo WARN: Cannot load device tree; " \
			"fi; " \
		"else " \
			"echo WARN: Cannot load kernel image; " \
		"fi;\0" \
	"raucboot=" \
		"test -n \"${BOOT_ORDER}\" || setenv BOOT_ORDER \"system0 system1\"; " \
		"test -n \"${BOOT_system0_LEFT}\" || setenv BOOT_system0_LEFT 3; " \
		"test -n \"${BOOT_system1_LEFT}\" || setenv BOOT_system1_LEFT 3; " \
		"setenv raucstatus; " \
		"for BOOT_SLOT in \"${BOOT_ORDER}\"; do " \
			"if test \"x${raucstatus}\" != \"x\"; then " \
				"echo Skipping remaing slots!; " \
			"elif test \"x${BOOT_SLOT}\" = \"xsystem0\"; then " \
				"if test ${BOOT_system0_LEFT} -gt 0; then " \
					"echo \"Found valid slot A, " \
						"${BOOT_system0_LEFT} attempts remaining\"; " \
					"setexpr BOOT_system0_LEFT ${BOOT_system0_LEFT} - 1; " \
					"setenv raucbootpart ${raucbootpart0}; " \
					"setenv raucrootpart ${raucrootpart0}; " \
					"setenv raucslot system0; " \
					"run raucargs; " \
					"setenv raucstatus success; " \
				"fi; " \
			"elif test \"x${BOOT_SLOT}\" = \"xsystem1\"; then " \
				"if test ${BOOT_system1_LEFT} -gt 0; then " \
					"echo \"Found valid slot B, " \
						"${BOOT_system1_LEFT} attempts remaining\"; " \
					"setexpr BOOT_system1_LEFT ${BOOT_system1_LEFT} - 1; " \
					"setenv raucbootpart ${raucbootpart1}; " \
					"setenv raucrootpart ${raucrootpart1}; " \
					"setenv raucslot system1; " \
					"run raucargs; " \
					"setenv raucstatus success; " \
				"fi; " \
			"fi; " \
		"done; " \
		"if test -n \"${raucstatus}\"; then " \
			"env delete raucstatus; " \
			"saveenv; " \
			"run raucemmcboot; " \
		"else " \
			"echo \"WARN: No valid slot found\"; " \
			"setenv BOOT_system0_LEFT 3; " \
			"setenv BOOT_system1_LEFT 3; " \
			"env delete raucstatus; " \
			"saveenv; " \
			"reset; " \
		"fi;\0"

/* The minimal subset of environment variables that RAUC needs to read/write
 * from environment storage. This can be used by locked-down builds, i. e. when
 * u-boot is to be used in a secureboot context.
 *
 * The following ruleset will only apply if CONFIG_ENV_WRITEABLE_LIST is set
 * */
#define RAUC_REQUIRED_WRITABLE_ENV_FLAGS "BOOT_ORDER:sw,BOOT_system0_LEFT:dw,BOOT_system1_LEFT:dw,doraucboot:dw"

#endif /* __PHYCORE_RAUC_ENV_H */
