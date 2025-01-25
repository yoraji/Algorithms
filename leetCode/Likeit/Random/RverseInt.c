#include<stdio.h>
#include<stdlib.h>
char* itoa(int x){
    char* head = malloc(12);
    if(head == NULL) return NULL;
    int i=0;
    int Negative = 0;
    if(x<0){
        Negative = 1;
        x = -x;
    }
    do{
        head[i++] = (x%10)+'0';
        x /=10;
    }while(x != 0);
    if(Negative) {
        head [i++] = '-';
    }
    head[i] = '\0';
    for(int j=0;j<i/2;j++){
        char temp = head[j];
        head[j] = head[i-j-1];
        head[i-j-1] = temp;
    }
    return head;
}

int ReverseInt(int x){
    char *head = itoa(x);
    int len = 0;
    while(head[len]) 
        len++;
    int reversed = 0;
    for(int i=len-1; i>= 0;i--) {
        if(head[i] == '-')
            continue;
        reversed = reversed * 10 +(head[i]-'0');
    }
    if(x<0)
        reversed = -reversed;
    free(head);
    return reversed;
}

//main function
int main(){
    int x = 123;
    x = ReverseInt(x);
    printf("%d\n",x);
}
