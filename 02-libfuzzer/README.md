# Lab 02: libFuzzer

## Goal

Use LLVM's in-process, coverage-guided fuzzer with a small C entry point.

## Install tools on Ubuntu

```sh
sudo apt update
sudo apt install clang make
```

## Build and fuzz

```sh
make build
make fuzz
```

`LLVMFuzzerTestOneInput` receives mutated bytes directly, so no file-reading
`main` function is needed. libFuzzer keeps useful inputs in `corpus/` and saves
crashes as `artifacts/crash-*`. It starts with an empty input and creates its
own corpus, so this lab does not need a seed file. Stop fuzzing with Ctrl-C.

The hidden condition is `LIBFUZZ`. After the fuzzer finds it, replay the first
saved crash artifact with:

```sh
make reproduce
```

If no artifact exists yet, the target asks you to run `make fuzz` first.

The build also enables AddressSanitizer and UndefinedBehaviorSanitizer. Run
`make clean` to remove generated files.

## Next lab

Lab 03 compares this workflow with AFL++ source instrumentation and a
file-based harness.
