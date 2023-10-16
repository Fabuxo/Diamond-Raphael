#!/bin/bash
# SPDX-License-Identifier: GPL-2.0

# Clean job first
make clean && make mrproper

make O=out ARCH=arm64 raphael_defconfig

PATH="/home/ghost/clang/bin:/home/ghost/gcc64/bin:/home/ghost/gcc32/bin:${PATH}" \
make -j$(nproc --all) O=out \
                      ARCH=arm64 \
                      CC=clang \
                      CLANG_TRIPLE=aarch64-linux-gnu- \
                      CROSS_COMPILE=aarch64-linux-android- \
                      CROSS_COMPILE_ARM32=arm-linux-androideabi-

