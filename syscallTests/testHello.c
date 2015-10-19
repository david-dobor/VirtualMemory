#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

int main()
{
    long int sysreturn = syscall(359);
    printf("System call sys_hello returned %ld\n", sysreturn);
    return 0;
}
