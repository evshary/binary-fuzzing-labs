CC := afl-clang-fast
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O1 -g
TARGET := target
SANITIZED_TARGET := target-sanitized

.PHONY: build build-sanitized fuzz reproduce clean help

help:
	@echo "Available targets:"
	@echo "  build            Build the AFL++-instrumented target"
	@echo "  build-sanitized  Build with AddressSanitizer and UBSan"
	@echo "  fuzz             Start AFL++ with a generated input"
	@echo "  reproduce        Reproduce the known crash deterministically"
	@echo "  clean            Remove generated binaries and AFL++ outputs"
	@echo "  help             Show this help"

build: $(TARGET)

$(TARGET): target.c
	$(CC) $(CFLAGS) $< -o $@

build-sanitized: $(SANITIZED_TARGET)

$(SANITIZED_TARGET): target.c
	$(CC) $(CFLAGS) -fsanitize=address,undefined -fno-omit-frame-pointer $< -o $@

fuzz: build
	mkdir -p input
	printf 'A' > input/start
	afl-fuzz -i input -o out -- ./$(TARGET) @@

reproduce: build
	@./$(TARGET) regression/FUZZBUG!; status=$$?; \
	if [ $$status -eq 0 ]; then \
		echo "Error: regression input did not crash" >&2; exit 1; \
	fi; \
	echo "Crash reproduced (exit status $$status)"

clean:
	rm -rf $(TARGET) $(SANITIZED_TARGET) input out out-sanitized
