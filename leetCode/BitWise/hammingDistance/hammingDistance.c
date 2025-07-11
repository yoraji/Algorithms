#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hammingDistance(int x, int y) {

    int num = x ^ y;
    int counter = 0;
    while(num)
    {
        if(num % 2 == 1)
            counter++;
        num /= 2;
    }
    return counter;
}

int main() {
    int x = 1, y = 4;
    printf("Hamming Distance between %d and %d is: %d\n", x, y, hammingDistance(x, y));
    return 0;
}