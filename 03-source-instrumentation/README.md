# Lab 03: Source Instrumentation with AFL++

## Goal

Compile a file-based C target with AFL++ and find a hidden `FUZZBUG!` crash.

## Install tools on Ubuntu

```sh
sudo apt update
sudo apt install afl++ build-essential clang llvm make
```

Verify the installation with `afl-clang-fast --version`.

## Files

- `target.c` reads up to 1024 bytes and calls a separate parser.
- `regression/FUZZBUG!` reproduces the known crash but is not a seed.
- AFL++ uses coverage feedback to keep inputs that reach new parser paths.

## Build and inspect

```sh
make build
file target
nm target | grep parse_input
```

## Fuzz and reproduce

```sh
make fuzz
make reproduce
```

`make fuzz` creates a disposable one-byte starting input because AFL++ requires
a non-empty input corpus. Fuzzer crashes appear in `out/default/crashes/`.
Stop fuzzing with Ctrl-C. On Ubuntu systems where AFL++ rejects crash handling
or CPU scaling settings, a short learning session can use:

```sh
AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_SKIP_CPUFREQ=1 make fuzz
```

For long campaigns, apply the system configuration suggested by `afl-fuzz`.

## Sanitizers and cleanup

```sh
make build-sanitized
./target-sanitized regression/FUZZBUG!
make clean
```

The sanitizer build helps diagnose real memory errors. This example uses an
intentional trap, so the regression input simply terminates with a signal.
