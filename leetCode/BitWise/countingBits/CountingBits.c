#include<stdio.h>
#include<stdlib.h>

int bit(int n){
    int counter=0;
    while(n != 0){
        n &= (n-1);
        counter++;
    }
    return counter;
}

int *CountBits(int arr,int size){
    int *head = (int*)malloc(sizeof(size));
    if(head == NULL)
        return NULL;
    for(int i=0;i<=arr;i++){
        head[i] = bit(i);
    }
    return head;
}

int main(){
    int n =5;
    int size=6;
    int *res = CountBits(n,size);
    for(int i=0;i<6;i++){
        printf("%d ",res[i]);
    }
    return 0;
}
