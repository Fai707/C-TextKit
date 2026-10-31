#include <stdio.h>

int max(int x, int y, int z);
int min(int x, int y, int z);

int main(){
    int x;
    int y;
    int z;
    scanf("%d %d %d", &x, &y, &z);

    printf("sum: %d\n", x+y+z);
    printf("max: %d\n", max(x, y, z));
    printf("min: %d\n", min(x, y, z));
    
}

// max(x,y,z) = (x > z) ? ((x > y) ? x : y) : ((z > y) ? z : y)
// min(x,y,z) = (x < z) ? ((x < y) ? x : y) : ((z < y) ? z : y)

int max(int x, int y, int z){
    return (x > z) ? ((x > y) ? x : y) : ((z > y) ? z : y);
}
int min(int x, int y, int z){
    return (x < z) ? ((x < y) ? x : y) : ((z < y) ? z : y);
}
