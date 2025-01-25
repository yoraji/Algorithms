#include<stdio.h>

int complement(int n){
    int temp = n;
    int counter =0;
    while(temp != 0){
        temp>>=1;
        counter++;
    }
    int mask = ((1<<counter)-1);
    return mask^n;
}

int main(){
    int n =7;
    n = complement(n);
    printf("%d\n",n);
    return 0;
}
