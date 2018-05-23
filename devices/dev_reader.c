#include <fcntl.h>
#include <linux/input.h>

void check_unix_device_events(char *unix_device_location) {
    
    int fd;
    fd = open(unix_device_location, O_RDONLY);
    struct input_event ev;

    while (1) {
        read(fd, &ev, sizeof(struct input_event));
        printf("%i, %i, %i\n\n", ev.type, ev.value, ev.code);
    }

    close(fd);
}

void check_unix_device_raw(char *unix_device_location) {
    
    int fd;
    fd = open(unix_device_location, O_RDONLY);
    int buff;

    while (1) {
        read(fd, &buff, sizeof(int));
        printf("%i", buff);
    }

    close(fd);
}