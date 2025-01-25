#include<stdio.h>

int bit(int n){
    int count=0;
    while(n != 0 ){
        n &= n-1;
        count++;
    }
    return count;
}

int main(){
    int n = 11;
    n = bit(n);
    printf("%d\n",n);
}
