#include<stdio.h>

// Using Hashtable methode (more effiecnt methode):
// Time complexity O(n):
int findDuplicate(int *nums,int size){
    int hash[500000] = {0};
    for(int i=0;i<size;i++){
        hash[nums[i]]++;
        if(hash[nums[i]] == 2){
            return nums[i];
        }
    }
    return -1;
}
// another methode (the classic way let's say)
int findDuplicate1(int *nums,int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(arr[i] == arr[j]){
                return arr[i];
            }
        }
    }
    return -1;  
}
