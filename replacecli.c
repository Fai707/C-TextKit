#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc != 4){
        return 1;
    }
    char *start = argv[1];
    char *from = argv[2];
    char *to = argv[3];
    char destination[256];
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