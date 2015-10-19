## Project on Virtual Memory, in Progress...

The following has been completed: 

### Adding a Sample System Call to the Linux Kernel

[How to add a system call to the linux kernel](https://github.com/david-dobor/VirtualMemory/tree/master/Preliminaries) (kernel version 3.19, 32 bit.)

### The `simple` Module 
`simple.c` iterates over the processes running on the 
system and outputs (to the kernel log buffer) some basic information about each process. 

Steps to compile, load, check output, and remove the module:

```
        make                   # compile the module 
        sudo insmod simple.ko  # insert the module
        dmesg                  # check the log buffer to see the outuput
        sudo rmmod simple      # remove the module
        #sudo dmesg -c         # clears the kernel log
```
