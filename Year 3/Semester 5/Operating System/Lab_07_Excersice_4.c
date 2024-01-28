#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/fs.h>

int main() {
    int fd = open("/dev/sda", O_RDWR);

    if (fd < 0) {
        printf("Error: Failed to open device.\n");
        exit(1);
    }

    char buffer[512] = "Hello, world!";
    off_t offset = 0x100000; // Sector number to write to

    if (lseek(fd, offset * 512, SEEK_SET) < 0) {
        printf("Error: Failed to seek to sector.\n");
        close(fd);
        exit(1);
    }

    if (write(fd, buffer, sizeof(buffer)) < 0) {
        printf("Error: Failed to write to sector.\n");
        close(fd);
        exit(1);
    }

    close(fd);

    return 0;
}
