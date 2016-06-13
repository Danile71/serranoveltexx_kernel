#!/bin/bash
export ARCH=arm
export CROSS_COMPILE="/home/danil_e71/android-toolchain-eabi-4.9/bin/arm-eabi-"

mkdir $(pwd)/out
mkdir $(pwd)/out/boot/
mkdir $(pwd)/out/boot/modules/


make -C $(pwd) O=out msm8916_sec_defconfig VARIANT_DEFCONFIG=msm8916_sec_serranovelte_eur_defconfig SELINUX_DEFCONFIG=selinux_defconfig
make -C $(pwd) O=out



cp $(pwd)/out/arch/arm/boot/zImage $(pwd)/out/boot/boot.img-kernel

$(pwd)/dtbTool -2 -o ./out/boot/boot.img-dt -s 2048 -p ./out/scripts/dtc/ ./out/arch/arm/boot/dts/ -v

find $(pwd)/out/drivers/   -name "*.ko" -exec cp {} $(pwd)/out/boot/modules/  \;

