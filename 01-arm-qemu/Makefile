CROSS_CC ?= aarch64-linux-gnu-gcc
QEMU ?= qemu-aarch64
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O1 -g -static
TARGET := hello-arm64

.PHONY: build inspect run clean help

help:
	@echo "make build    Cross-compile the ARM64 binary"
	@echo "make inspect  Inspect its architecture and ELF header"
	@echo "make run      Run it with QEMU user mode"
	@echo "make clean    Remove the binary"

build: $(TARGET)

$(TARGET): hello.c
	$(CROSS_CC) $(CFLAGS) $< -o $@

inspect: build
	file $(TARGET)
	readelf -h $(TARGET)

run: build
	$(QEMU) ./$(TARGET) learner

clean:
	rm -f $(TARGET)
