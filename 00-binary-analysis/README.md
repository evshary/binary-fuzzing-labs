# Lab 00: Binary Analysis Basics

## Goal

Build a small native program and learn what common binary tools reveal.

## Prerequisites

On Ubuntu:

```sh
sudo apt update
sudo apt install build-essential binutils file
```

## Try it

```sh
make build
file target
readelf -h target
readelf -S target
nm -C target | grep check_word
objdump -d target | less
strings target | grep BINARY
./target BINARY
```

- `file` identifies the format and architecture.
- `readelf` displays ELF headers and sections.
- `nm` lists symbols, including the separate `check_word` function.
- `objdump` disassembles machine code.
- `strings` finds readable text embedded in the file.

Run `make inspect` for the full output and `make clean` when finished.

## Next lab

Lab 01 cross-compiles a Linux program for ARM64 and runs it with QEMU.
