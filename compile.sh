#/bin/bash

gcc ./server.c -o ./server
if [ "$1" = "gcc" ]; then
    
    gcc ./devices/*/*.c ./client.c -o ./client_gcc
elif [ "$1" = "arm32" ]; then
    
    arm-linux-gnueabi-gcc -static ./devices/*/*.c ./client.c -o ./client_arm32
    if [ "$2" = "adb-push" ]; then
    
        adb push ./client_arm32 /data/local/tmp/
        if [ "$3" = "adb-run" ]; then

            adb shell "/data/local/tmp/client_arm32"
        fi
    
    fi
else
    echo "Please, choose compilation mode [gcc | arm32]"
fi