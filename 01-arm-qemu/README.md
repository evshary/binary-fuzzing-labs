# Lab 01: ARM64 with QEMU

## Goal

Cross-compile a Linux program for ARM64, inspect it, and run it on an x86-64
Ubuntu host with QEMU user mode.

## Install tools on Ubuntu

```sh
sudo apt update
sudo apt install gcc-aarch64-linux-gnu qemu-user binutils make
```

## Build and run

```sh
make build
file hello-arm64
readelf -h hello-arm64
make run
```

The cross-compiler produces ARM64 instructions instead of host instructions.
The binary is linked statically, so QEMU does not need a separate ARM64 root
filesystem:

```sh
qemu-aarch64 ./hello-arm64 learner
```

Expected output includes `Hello, learner, from ARM64!`. Run `make clean` when
finished.

## Next lab

Lab 02 introduces in-process coverage-guided fuzzing with libFuzzer.
