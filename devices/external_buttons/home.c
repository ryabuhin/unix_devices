#include <fcntl.h>
#include <linux/input.h>

#define DEVICE_HOME_BUTTON_EVENT "/dev/input/event1"

void emulate_press_home_button_event() {

    int fd;
    fd = open(DEVICE_HOME_BUTTON_EVENT, O_WRONLY | O_APPEND);
    struct input_event sendEvent[2];

    sendEvent[0].type = 1;
    sendEvent[0].value = 1;
    sendEvent[0].code = 102;

    sendEvent[1].type = 0;
    sendEvent[1].value = 0;
    sendEvent[1].code = 0;

    write(fd, &sendEvent, sizeof(struct input_event) * 2);

    close(fd);
}

void emulate_unpress_home_button_event() {

    int fd;
    fd = open(DEVICE_HOME_BUTTON_EVENT, O_WRONLY | O_APPEND);
    struct input_event sendEvent[2];

    sendEvent[0].type = 1;
    sendEvent[0].value = 0;
    sendEvent[0].code = 102;

    sendEvent[1].type = 0;
    sendEvent[1].value = 0;
    sendEvent[1].code = 0;

    write(fd, &sendEvent, sizeof(struct input_event) * 2);

    close(fd);
}