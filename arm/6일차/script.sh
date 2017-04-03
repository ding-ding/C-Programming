#!/bin/bash
arm-linux-gnueabi-gcc -O0 -mcpu=cortex-a9 -mfloat-abi=softfp -mfpu=neon arm_neon_asm.c
qemu-arm-static -g 1234 -L /usr/arm-linux-gnueabi ./a.out &
gdb-multiarch -q -iex "set auto-load safe-path ./" ./gdb
