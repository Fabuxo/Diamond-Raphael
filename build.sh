#!/bin/bash
# SPDX-License-Identifier: GPL-2.0

# Clean job first
make clean && make mrproper

make O=out ARCH=arm64 raphael_defconfig

PATH="/home/ghost/clang/bin:${PATH}" \
make -j$(nproc --all) O=out \
      ARCH=arm64 \
      LD=ld.lld \
      NM=llvm-nm \
      AR=llvm-ar \
      CC="ccache clang" \
      CLANG_TRIPLE=aarch64-linux-gnu- \
      CROSS_COMPILE=aarch64-linux-gnu- \
      CROSS_COMPILE_ARM32=arm-linux-gnueabi-

