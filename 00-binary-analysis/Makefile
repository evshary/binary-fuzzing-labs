CC ?= cc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O0 -g

.PHONY: build inspect run clean help

help:
	@echo "make build    Compile the example"
	@echo "make inspect  Show basic binary information"
	@echo "make run      Run the example"
	@echo "make clean    Remove the binary"

build: target

target: target.c
	$(CC) $(CFLAGS) $< -o $@

inspect: build
	file target
	readelf -h -S target
	nm -C target
	objdump -d target
	strings target

run: build
	./target BINARY

clean:
	rm -f target
