#include<stdio.h>

int rangeBitwiseAnd(int left,int right){
    int shifter =0;
    while(right>left){
        right >>= 1;
        left >>= 1;
        shifter++;
    }
    return left << shifter;
}
int main(){
    int left =1;
    int right =2147483647;
    int result = rangeBitwiseAnd(left,right);
    printf("%d\n",result);
}
