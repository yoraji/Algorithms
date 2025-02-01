#include <stdio.h>

int bin(int num)
{
	int res = 0;
	while(num)
	{
		res += num & 1;
		num >>= 1;
	}
	return res;
}

int hammingDistance(int x, int y) {
	int CountXor = x ^ y; // for different bits
	return (bin(CountXor));
}

int main()
{
	int num = 1;
	int num1 = 4;
	int res = hammingDistance(num, num1);
	printf("%d\n",res);
	return 0;
}
