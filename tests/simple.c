#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/list.h>
#include <linux/mm.h>

//#include <linux/gfp.h>

struct birthday {
    int day;
    int month;
    int year;
    struct list_head list;
};

static unsigned long addr = 0;

/* This function is called when the module is loaded. */
int simple_init(void)
{
    static LIST_HEAD (birthday_list);
    /* Do birthday stuff later */
    printk(KERN_INFO "Loading Module\n");

    addr = __get_free_pages(GFP_KERNEL, 0); 
    printk("addr= 0x%x\n", (int)addr);
    strcpy((char *)addr, "Should I be working on this project now?\n");


    return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
    printk(KERN_INFO "Removing Module\n");
    ClearPageReserved(virt_to_page(addr));
    free_pages(addr, 0);
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("Dave");
