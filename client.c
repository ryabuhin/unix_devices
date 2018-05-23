#include <netinet/in.h>
#include <stdlib.h>

#define HOST "192.168.1.143"
#define PORT 8811

#define DEVICE_UNKNOWN1_EVENT "/dev/input/event3"
#define DEVICE_UNKNOWN2_EVENT "/dev/input/event4"

void wait_for_commands() {

    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, HOST, &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    while(1) { 
        
        read(sock, &valread, sizeof(int));

        switch(valread) {
            case 1:
                emulate_press_power_button_event();
                emulate_unpress_power_button_event();
                break;
            case 2:
                emulate_press_home_button_event();
                emulate_unpress_home_button_event();
                break;
            case 3:
                emulate_press_volume_up_button_event();
                emulate_unpress_volume_up_button_event();
                break;
            case 4: 
                emulate_press_volume_down_button_event();
                emulate_unpress_volume_down_button_event();
                break;
            case 5:
                exit(0);
        }
    }

}

int main(int argc, char const *argv[]) {
    wait_for_commands();
    return 0;
}