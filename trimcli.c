#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    char *start;
    if (argc != 2 && argc != 3) {
        fprintf(stderr, "Usage: trimcli [option] \"text\"\n");
        return 1;
    }

    if (argc == 3) {
        start = argv[2];
    } else if (argc == 2) {
        start = argv[1];
    } if (argc == 3 &&
        strcmp(argv[1], "--left") != 0 &&
        strcmp(argv[1], "--right") != 0) {
        fprintf(stderr, "Unknown option: %s\n", argv[1]);
        return 1;
    }
    char *end = start + strlen(start);
    char *original = start;
    if (argc == 2 || strcmp(argv[1], "--right") == 0){
        while (end > start && (end[-1] == ' ' || end[-1] == '\t')) {
            end--;
        }
    }
    if (argc == 2 || strcmp(argv[1], "--left") == 0){
        while (start < end && (*start == ' ' || *start == '\t')) {
            start++;
        }
    }
    size_t length = (size_t)(end - start);
    char *buffer = original;

    while (start < end) {
        *buffer = *start;
        start++;
        buffer++;
    }

    *buffer = '\0';

    printf("[%s]\nlength: %zu\n", original, length);
}