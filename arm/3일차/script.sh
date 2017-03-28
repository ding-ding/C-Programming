#!/bin/bash
arm-linux-gnueabi-gcc -O0 -g arm_clz_pow1.c 
qemu-arm-static -g 1236 -L /usr/arm-linux-gnueabi ./a.out &
gdb-multiarch -q -iex "set auto-load safe-path ./" ./gdb
