#!/bin/bash
arm-linux-gnueabi-gcc -O0 -g arm_fork_sol.c 
qemu-arm-static -g 1234 -L /usr/arm-linux-gnueabi ./a.out &
gdb-multiarch -q -iex "set auto-load safe-path ./" ./gdb
