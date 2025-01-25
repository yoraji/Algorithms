#include<stdio.h>
#include<string.h>

#define n 3
#define m 4
int ft_strlen(char *ptr){
	int i=0;
	while(ptr[i])
		i++;
	return i;
}

int backtraking(char str[n][m],char *s,int i,int j,int index,int valide[n][m]){
	if(index == ft_strlen(s))return 1;
	if(i<0 || i >= n || j <0 || j >= m || valide[i][j] || str[i][j] != s[index]) return 0;
	valide[i][j] = 1;
	int found = 	backtraking(str,s,i-1,j,index+1,valide) || 
			backtraking(str,s,i,j-1,index+1,valide) ||
			backtraking(str,s,i+1,j,index+1,valide) ||
			backtraking(str,s,i,j+1,index+1,valide);
	valide[i][j] = 0;
	return found;
}

int searching (char str[n][m],char *s)
{
	int i=0;int j=0;int index=0;
	char c = s[0];
	int valide[n][m]={0};
	for(i=0; i<n;i++){
		for(j=0;j<m;j++){
			if(str[i][j] == c && backtraking(str,s,i,j,index,valide)==1){
				return 1;
			}
		}
	}
	return 0;
}


int main(){
	char str[n][m] = {
		{'a','b','c','e'},
		{'s','f','c','s'},
		{'a','d','e','e'},
	};
	char *s = "abcesco";
	int result = searching(str,s);
	if(result == 1)
		printf("True\n");
	else 
		printf("False\n");


