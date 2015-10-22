## A Project on Virtual Memory, in Progress...


The following has been completed: 

#### Adding a Sample System Call to the Linux Kernel

[How to add a system call to the linux kernel](https://github.com/david-dobor/VirtualMemory/tree/master/Preliminaries) (kernel version 3.19, 32 bit.)


### In this directory, so far:

### Kernel Modules

+ `meminfo.c` iterates through all running processes and finds the
   process with a given `pid`; Prints address information for the
   various virtual memory segments allocated to that process, such as
   the address range for the data segment, for the BSS, for the code
   segment, etc.


### User Space Addresses, an Example

+ `user.c` prints the addresses of its local and global variables, and
   the address of a function it calls. These addresses fall into
   distinct memory segments (memory areas) that are maintained by the
   kernel.
   
   Kernel module `meminfo.c` verifies that these addresses indeed fall
   into the various memory areas maintained by the kernel. For
   example, the address range for the `code segment` should contain
   the address of the function called by the program; the data segment
   should contain the address of the initialized global variable,
   etc. (The kernel keeps track of the memory areas in the linked list
   of `vm_area_struct`s.)


### Other: 
   
Steps to compile, load, check output, and remove the module:

        make                   # compile the module 
        sudo insmod simple.ko  # insert the module
        dmesg                  # check the log buffer to see the outuput
        sudo rmmod simple      # remove the module
        #sudo dmesg -c         # clears the kernel log
