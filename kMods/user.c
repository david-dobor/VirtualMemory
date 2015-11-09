/* Prints a few representative addresses within 
 * within the virtual address space of the process
 * running this program.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int global_init = 30;		/*   initialized data: Data Segment */
int global_noinit;     		/* uninitialized data: BSS Segment */

void this_func(void)		/* Code Segment */
 {
         int local = 1;    	/* locals go to the stack */
         printf("\nPid of the process is = %d", getpid());
         printf("\nSegments Containing Addresses:");
         printf("\n 1. Address from the Data  Segment = %p", &global_init);
         printf("\n 2. Address from the BSS   Segment = %p", &global_noinit);
         printf("\n 3. Address from the Code  Segment = %p", &this_func);
         printf("\n 4. Address from the Stack Segment = %p\n", &local);

	 while(1);  
 }
int main()
{
        this_func();
        return 0;
}

