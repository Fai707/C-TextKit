#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc != 4){
        fprintf(stderr, "Usage: replacecli \"text\" from to\n");
        return 1;
    }

    char destination[256];
    size_t length = strlen(argv[1]);
        if (length >= sizeof destination) {
        fprintf(stderr, "Error: input too long (maximum 255 characters)\n");
        return 1;
    }

    char *start = argv[1];
    char *from = argv[2];
    char *to = argv[3];
    char *write = destination;
    
    while(*start != '\0'){
        if(*start == *from){
            *write = *to;
        }else{
            *write = *start;
        }
        write++;
        start++;
    }
    *write = '\0';

    printf("%s", destination);
}