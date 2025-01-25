#include<stdio.h>
#include<stdlib.h>

char* longestCommonPrefix(char** strs,int strsSize) {
    if(strsSize == 0)
        return "";
    char* ptr = malloc(sizeof(char)*1000);
    int i=1;int j=0;
    while(strs[0][j]){
        for(int i=1;i<strsSize;i++){
            if(strs[i][j] != strs[0][j]){
                ptr[j] = '\0';
                return ptr;
            }
        }
        ptr[j] = strs[0][j];
        j++;
    }
    ptr[j] = '\0';
    return ptr;
}

int main(){
    char* strs[] = {"flower","flow","flight"};
    int size = 3;
    char* ptr =  longestCommonPrefix(strs,size);
    printf("%s\n",ptr);
    return 0;
}
