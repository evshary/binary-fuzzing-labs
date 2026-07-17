#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    if (size >= 7 && data[0] == 'L' && data[1] == 'I' && data[2] == 'B' &&
        data[3] == 'F' && data[4] == 'U' && data[5] == 'Z' && data[6] == 'Z') {
        __builtin_trap();
    }

    return 0;
}
