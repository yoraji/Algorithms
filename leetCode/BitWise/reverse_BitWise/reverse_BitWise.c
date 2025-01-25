#include <stdint.h> 
#include <stdio.h> 

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        uint32_t c = n %2;
	n /= 2;
	result = result << 1 | c;
    }
    return result;
}
int main() {
    uint32_t number = 43261596;
    uint32_t reversed = reverseBits(number);
    printf("Original: %u \n", number);
    printf("Reversed: %u \n", reversed);
    return 0;
}
