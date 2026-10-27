#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){
    if (argc != 2) {
        fprintf(stderr, "Usage: argsplit \"text\"\n");
        return 1;
    }

    char buffer[256];
    size_t length = strlen(argv[1]);

    if (length >= sizeof buffer) {
        fprintf(stderr, "Error: input too long (maximum 255 characters)\n");
        return 1;
    }

    const char *read = argv[1];
    char *write = buffer;

    while (*read != '\0') {
        *write = *read;
        read++;
        write++;
    }

    *write = '\0';
    char *start = buffer;
    char *arguments[16];
    int count = 0;
    int inside_word = 0;

    while (*start != '\0'){

        if (*start == ' ' || *start == '\t') {
            *start = '\0';
            inside_word = 0;
        }
        else if (inside_word == 0) {
            if (count == 15) {
                fprintf(stderr, "Error: too many arguments (maximum 15)\n");
                return 1;
            }
            arguments[count] = start;
            count++;
            inside_word = 1;
        }

        start++;
    }
    arguments[count] = NULL;
    
    printf("argc: %d\n", count);

    for (int i = 0; i < count; i++) {
        printf("argv[%d]: [%s]\n", i, arguments[i]);
    }

}