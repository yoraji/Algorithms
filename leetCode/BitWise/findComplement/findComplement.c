#include<stdio.h>

int findComplement(int num){
    int mask =0;
    while((num & ~mask) != 0){
        mask = (mask << 1) | 1;
    }
    return mask;
}
int main(){
    int num =5;
    num=findComplement(num);
    printf("%d\n",num);
}
