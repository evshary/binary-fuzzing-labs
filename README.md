# Binary Analysis and Fuzzing Labs

Small, hands-on labs that introduce binary tooling before progressing to
coverage-guided fuzzing.

## Learning path

| Lab | Topic |
| --- | --- |
| [Lab 00](00-binary-analysis/) | Inspect a native binary |
| [Lab 01](01-arm-qemu/) | Cross-compile and run ARM64 code with QEMU |
| [Lab 02](02-libfuzzer/) | Fuzz an in-process target with libFuzzer |
| [Lab 03](03-source-instrumentation/) | Source instrumentation with AFL++ |

Each lab is self-contained. Enter its directory and follow its README to build
and run the exercises.

Run `make clean` from this directory to remove generated files from every lab.
