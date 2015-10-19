#include <linux/kernel.h>

asmlinkage long sys_hello(void)
{
  printk("Hello from David!\n");
  return 0;
}
