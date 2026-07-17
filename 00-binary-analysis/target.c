#include <stdio.h>
#include <stdlib.h>
#include <string.h>

__attribute__((noinline)) static int check_word(const char *word) {
    size_t length = strlen(word);

    if (length > 0 && word[0] == 'B') {
        if (length > 1 && word[1] == 'I') {
            if (strcmp(word, "BINARY") == 0) {
                return 3;
            }
            return 2;
        }
        return 1;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s WORD\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Matched level: %d\n", check_word(argv[1]));
    return EXIT_SUCCESS;
}
