#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s NAME\n", argv[0]);
        return EXIT_FAILURE;
    }

#if defined(__aarch64__)
    printf("Hello, %s, from ARM64!\n", argv[1]);
#else
    printf("Hello, %s, from an unexpected architecture.\n", argv[1]);
#endif
    return EXIT_SUCCESS;
}
