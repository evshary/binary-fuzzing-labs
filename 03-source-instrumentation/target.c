#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024U

__attribute__((noinline)) static void parse_input(const unsigned char *data,
                                                   size_t size) {
    if (size > 0 && data[0] == 'F') {
        if (size > 1 && data[1] == 'U') {
            if (size > 2 && data[2] == 'Z') {
                if (size > 3 && data[3] == 'Z') {
                    if (size > 4 && data[4] == 'B') {
                        if (size > 5 && data[5] == 'U') {
                            if (size > 6 && data[6] == 'G') {
                                if (size > 7 && data[7] == '!') {
                                    __builtin_trap();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, char **argv) {
    unsigned char data[MAX_INPUT_SIZE];
    size_t size;
    FILE *input;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s INPUT_FILE\n", argv[0]);
        return EXIT_FAILURE;
    }

    input = fopen(argv[1], "rb");
    if (input == NULL) {
        fprintf(stderr, "Could not open '%s': %s\n", argv[1], strerror(errno));
        return EXIT_FAILURE;
    }

    size = fread(data, 1, sizeof(data), input);
    if (ferror(input)) {
        fprintf(stderr, "Could not read '%s': %s\n", argv[1], strerror(errno));
        fclose(input);
        return EXIT_FAILURE;
    }

    if (fclose(input) != 0) {
        fprintf(stderr, "Could not close '%s': %s\n", argv[1], strerror(errno));
        return EXIT_FAILURE;
    }

    parse_input(data, size);
    return EXIT_SUCCESS;
}
