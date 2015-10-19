#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define PAGE_SIZE (4 * 1024)

#define KERNEL_ADDR 0xf2aa7000

int main()
{
    char *map = NULL;
    int fd;

    fd = open("/dev/mem" ,O_RDWR);
    if (fd < 0) {
	printf("Failed to open the /dev/mem "); exit(-1);}

    map = (char *) mmap(0, PAGE_SIZE,
		       O_RDWR, MAP_SHARED,
		       fd, KERNEL_ADDR);

    for (int i = 0; i < 10; i++) {
	printf("content: 0x%d\n", *(map + i));
    }


    munmap(map, PAGE_SIZE);

    close(fd);
    return 0;
}
