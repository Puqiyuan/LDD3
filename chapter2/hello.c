#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/version.h>
MODULE_LICENSE("Dual BSD/GPL");

static char *whom = "world";
static int howmany = 1;
module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);

static int hello_init(void)
{
	printk(KERN_ALERT "Hello, world\n");
	printk(KERN_INFO "The process is \"%s\" (pid %i)\n", current->comm, current->pid);
	printk(KERN_ALERT "%d\n", LINUX_VERSION_CODE);
	printk(KERN_ALERT "%d\n", KERNEL_VERSION(4, 18, 6));
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
