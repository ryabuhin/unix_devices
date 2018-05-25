# Unix philosophy about devices / Interaction with unix devices (android unix/linux kernel)
In the philosophy of Unix-like systems is assumed that all peripherals/devices connected to systems are files on the level of
file system. Is it really? Let's check.

### Little bit of theory
It is assumed that the I/O devices connected to the system are defined by files in the /dev/ directory.

### Devices for development
#### Notebook: 
* Processor: Intel Core i7-7700HQ 64-bit
* OS: Ubuntu 16.04
#### Mobile device Meizu MX4
* Processor: MediaTek MT6595 (4x ARM Cortex A-17 / 4x ARM Cortex A-7) 32-bit
* OS: Flyme 6.2.0.0G / Android 5.1

![](https://des.gbtcdn.com/uploads/2014/201409/heditor/201409021709072101.jpg)

#### Other soft for development
* gcc 5.4.0 - used for native compilation
* arm-linux-gnueabi-gcc 5.4.0 - used to compile under the mobile device
* adb driver - interaction with mobile via wifi or usb cable
* [Visual Studio Code](https://code.visualstudio.com/) or other text-editor for code

#### Precondition
1.  Device should be rooted by standard Flyme means in the *Settings* of meizu account
2.  Install [SuperSU](https://play.google.com/store/apps/details?id=eu.chainfire.supersu) application and flush your system 
with it for more system permissions
3.  Install [Terminal Emulator](https://play.google.com/store/apps/details?id=jackpal.androidterm) for simplified 
device management and configuration
4.  (Optional) Install [BusyBox](https://play.google.com/store/apps/details?id=stericson.busybox) for interaction 
with default linux binaries  
5.  On Ubuntu 16.04 install gnueabi-gcc and adb driver as follows:  

```no-highlight
# apt-get install gcc-arm-linux-gnueabi  
# apt-get install adb
```
#### Additional
To interact with the phone over the wireless network is used the adb driver. To do this, open the terminal 
emulator session on the phone and prescribe the following:

```no-highlight
$ su
# setprop service.adb.tcp.port 5555
# stop adbd
# start adbd
```

On the remote machine with installed adb make the next:

```no-highlight
$ adb kill-server
$ adb start-server
$ adb tcpip 5555
$ adb connect 192.168.1.100 # ipv4 address of the remote mobile device
```

And after this you can invoke the *adb shell / adb push* and other adb commands. For example:
```no-highlight
$ adb shell   #   will emulate sh session with remote device 
```

#### *...*