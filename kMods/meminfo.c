#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/mm.h>

static int gPid = 1;      	/* Process id to  */

static void print_mem(struct task_struct *task)
{
        struct mm_struct *mm;
        struct vm_area_struct *vma;
        int count = 0;
        mm = task->mm;
        printk("\nThis mm_struct has %d vmas.\n", mm->map_count);
        for (vma = mm->mmap ; vma ; vma = vma->vm_next) {
                printk ("\nVma number %d: \n", ++count);
                printk("  Starts at 0x%lx, Ends at 0x%lx\n",
                          vma->vm_start, vma->vm_end);
        }
        printk("\nCode  Segment start = 0x%lx, end = 0x%lx \n"
                 "Data  Segment start = 0x%lx, end = 0x%lx\n"
                 "Stack Segment start = 0x%lx\n",
                 mm->start_code, mm->end_code,
                 mm->start_data, mm->end_data,
                 mm->start_stack);
}

static int mm_init(void){
        struct task_struct *task;
        printk("\nLooking at process with id %d.\n", gPid);
        for_each_process(task) {
                if ( task->pid == gPid) {
                        printk("%s[%d]\n", task->comm, task->pid);
                        print_mem(task);
                }
        }
        return 0;
}

static void mm_exit(void)
{
        printk("\nAddress Info Module Exiting.\n");
}

module_init(mm_init);
module_exit(mm_exit);
module_param(gPid, int, 0);


MODULE_AUTHOR ("david.dobor@gmail.com");
MODULE_DESCRIPTION ("Print User Process Address Information");
MODULE_LICENSE("GPL");
