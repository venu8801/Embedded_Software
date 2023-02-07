/* basic driver code */
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

MODULE_AUTHOR("VENU GOPAL");
MODULE_LICENSE("GPL_v2");


static int hello_module(void)
{
	pr_info("module from userspace");
	pr_info("module loaded sucessfully\n");

	//printk(KERN_INFO "module from userspace");
	//printk(KERN_INFO "module loaded sucessfully\n");
	return 0;

}

static void hello_module_exit(void)
{
	pr_info("module from userspace");
	pr_info("module un-loaded sucessfully\n");

	//printk(KERN_INFO "module from userspace");
	//printk(KERN_INFO "module loaded sucessfully\n");
}

module_init(hello_module);
module_exit(hello_module_exit);



