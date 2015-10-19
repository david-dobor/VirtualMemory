//#include <linux/module.h>
#include <linux/kernel.h>
//#include <linux/mm.h>

MODULE_LICENSE(“GPL”);
MODULE_AUTHOR(“Runzhen”);
MODULE_DESCRIPTION(“mmap demo”);

static unsigned long addr = 0;

static int __init mod_init(void)
{
	//alloc a page
	addr = __get_free_pages(GFP_KERNEL, 0); //kernel virtual address
	SetPageReserved(virt_to_page(addr));

	printk(“addr= 0x%08x\n”, (int)addr);

	// write something
	strcpy((char *)addr, “With great power, comes great responsibility\n”);
	return 0;
}

static void __exit mod_exit(void)
{
	ClearPageReserved(virt_to_page(addr));
	free_pages(addr, 0);
}

module_init(mod_init);
module_exit(mod_exit);
