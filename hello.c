#include "hello.h"

int major = 0;

static int __init my_init(void)
{
    major = register_chrdev(0, "ETIB", &fops);
    printk("%d\n", major);
    return 0;
}

static void __exit my_exit(void)
{
    printk("goodbye\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("IDK");
MODULE_DESCRIPTION("My firt kernel module");
MODULE_AUTHOR("You");

static int is_open = 0;

static int my_dev_open(struct inode *inode, struct file *file)
{
    if (is_open == 0) {
        printk("Device is open\n");
        is_open = 1;
    } else {
        printk("Device is already open\n");
    }
    return 0;
}

static int my_dev_close(struct inode *inode, struct file *file)
{
    if (is_open == 1) {
        is_open = 0;
        printk("Device is closed\n");
    } else {
        printk("Device is already closed\n");
    }
    return 0;
}

static ssize_t my_dev_read(struct file *file, char *buf, size_t len, loff_t *off)
{
    return 0;
}

static ssize_t my_dev_write(struct file *file, char const *buf, size_t len, loff_t *off)
{
    return 0;
}