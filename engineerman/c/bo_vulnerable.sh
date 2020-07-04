#pi@raspberrypi:~ $ ./bo_vulnerable 
#enter password: aaaaaaaaaaaaaaaa
#usr_pass :aaaaaaaaaaaaaaaa
#sys_pass :
#auth val :0
#usr_pass   addr :0x7e99b45c
#sys_pass   addr :0x7e99b46c
#authorized addr :0x7e99b47c
#pi@raspberrypi:~ $ ./bo_vulnerable
#enter password: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
#usr_pass :aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
#sys_pass :aaaaaaaaaaaaaaaa
#auth val :0
#usr_pass   addr :0x7ee7045c
#sys_pass   addr :0x7ee7046c
#authorized addr :0x7ee7047c
#pi@raspberrypi:~ $ ./bo_vulnerable
#enter password: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
#usr_pass :aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
#sys_pass :aaaaaaaaaaaaaaaaa
#auth val :97
#usr_pass   addr :0x7eb2a45c
#sys_pass   addr :0x7eb2a46c
#authorized addr :0x7eb2a47c
#auth val :97
#password is correct!
#
#
#
#../../../../raspberry-pi/tools/arm-bcm2708/arm-bcm2708-linux-gnueabi/bin/arm-bcm2708-linux-gnueabi-gcc -v
#  ...
#
#  gcc version 4.7.1 20120402 (prerelease) (crosstool-NG 1.15.2) 
#
#  ...
#
#
#! /bin/bash

../../../../raspberry-pi/tools/arm-bcm2708/arm-bcm2708-linux-gnueabi/bin/arm-bcm2708-linux-gnueabi-gcc bo_vulnerable.c -o bo_vulnerable
