// SPDX-License-Identifier: GPL-2.0+
/*
* Copyright (c) 2019 Hyeonki Hong <hhk7734@gmail.com>
*/
 
#include <common.h>
#include <command.h>
 
static int do_print_hello(cmd_tbl_t * cmdtp, int flag, int argc,
                          char * const argv[]) {
        printf("Hello world!\n");
        return 0;
}




/* -------------------------------------------------------------------- */
 
U_BOOT_CMD(
        hello_android,  1,      0,      do_print_hello,
        "print \"Hello world!\"",
        "\n    - print \"Hello world!\""
)

