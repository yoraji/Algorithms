#include<stdio.h>

int bitwiseComplement(int n) {
    int counter = 0;
    int temp = n;

    while (temp > 0) {
        temp >>= 1;
        counter++;
    }
    int mask = (1 << counter) - 1;
    return n ^ mask;
}

int main(){
    int num = 5;
    num = bitwiseComplement(num);
    printf("%d\n",num);
}
