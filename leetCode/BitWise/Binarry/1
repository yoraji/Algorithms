#include<stdio.h>

void bin(unsigned n){
    if(n > 1)
        bin(n>>1);
    printf("%d",n&1);
}

int main(void){
    bin(5);
    printf("\n");
    bin (3);
    printf("\n");
    return 0;
}
