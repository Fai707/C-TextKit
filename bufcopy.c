#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc != 3) {
        fprintf(stderr, "Usage: bufcopy CAPACITY \"text\"\n");
        return 1;
    }

    char *end;
    long capacity = strtol(argv[1], &end, 10);
    
    if (end == argv[1] || *end != '\0' || capacity < 1 || capacity > 256) {
        fprintf(stderr, "Error: capacity must be an integer from 1 to 256\n");
        return 1;
    }

    const char *start = argv[2];
    char destination[256];
    char *write = destination;

    for (int i = 0; i < capacity - 1 && start[i] != '\0'; i++) {
        *write = *(start+i);
        write++;
    }
    *write = '\0';
    
    printf("[%s]\nlength: %td\ntruncated: %s\n", destination, write-destination, (start[write-destination] != '\0')? "yes" : "no");
    return start[write - destination] != '\0' ? 2 : 0;
}