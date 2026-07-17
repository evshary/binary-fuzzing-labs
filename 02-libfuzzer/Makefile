CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O1 -g
SANITIZERS := -fsanitize=fuzzer,address,undefined

.PHONY: build fuzz reproduce clean help

help:
	@echo "make build      Build the libFuzzer target"
	@echo "make fuzz       Start fuzzing"
	@echo "make reproduce  Replay a crash artifact"
	@echo "make clean      Remove generated files"

build: fuzzer

fuzzer: fuzz_target.c
	$(CC) $(CFLAGS) $(SANITIZERS) $< -o $@

fuzz: build
	mkdir -p corpus artifacts
	./fuzzer corpus -artifact_prefix=artifacts/

reproduce: build
	@set -- artifacts/crash-*; \
	if [ ! -e "$$1" ]; then \
		echo "No crash artifact found; run 'make fuzz' first" >&2; exit 1; \
	fi; \
	./fuzzer "$$1" -runs=1; status=$$?; \
	if [ $$status -eq 0 ]; then echo "Artifact did not crash" >&2; exit 1; fi; \
	echo "Crash reproduced (exit status $$status)"

clean:
	rm -rf fuzzer corpus artifacts
