#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/hdreg.h>

int main() {
    int fd = open("/dev/sda", O_RDONLY | O_NONBLOCK);

    if (fd < 0) {
        printf("Error: Failed to open disk.\n");
        exit(1);
    }

    struct hd_driveid id;

    if (ioctl(fd, HDIO_GET_IDENTITY, &id) < 0) {
        printf("Error: Failed to get disk identity.\n");
        close(fd);
        exit(1);
    }

    printf("Model: %s\n", id.model);
    printf("Serial number: %s\n", id.serial_no);

    close(fd);

    return 0;
}
