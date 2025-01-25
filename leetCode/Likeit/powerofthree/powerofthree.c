#include<stdio.h>

int isPowerOfThree(int n) {
	if(n <= 0)return 0; 
	while(n % 3 == 0){
        	n /= 3;
    	}
	if(n == 1) return 1;
	else
		return 0;
}
int main()
{
	int n =27;
	int res = isPowerOfThree(n);
	if(res ==1){printf("True\n");
	}else{
		printf("False\n");
	}
}
