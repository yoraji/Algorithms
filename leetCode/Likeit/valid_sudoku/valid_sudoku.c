#include<stdio.h>
#include<stdbool.h>

bool(validation(char** borad,int i,int j))
{
    char c = borad[i][j];
    if( c == '.')
        return 1;
    for(int p=0;p<9;p++){
        if(p != i && borad[p][j] == c ){
            return 0;
        }
    }
    for(int m=0;m<9;m++){
        if( m != j && borad[i][m] == c)
            return 0;
    }
    int row = (i/3)*3;
    int col = (j/3)*3;
    for(int k=row;k<row+3;k++){
        for(int u=col;u<col+3;u++){
            if(((i!=k)||(j!=u)) && borad[k][u] == c)
                return 0;
        }
    }
    return 1;

}
bool is_valid(char **board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(validation(board,i,j) == 0)
                return 0;
        }
    }
    return 1;
}
int main()
{
    char *board[9] = {
        "12..3....",
        "4..5.....",
        ".98......3",
        "5..6...4.",
        "...8.3...5",
        "7..2...6.",
        ".........2.",
        "...419..8",
        "....8..79"
    };	
	if(is_valid(board)){
		printf("true\n");
    }
	else{ 
		printf("false\n");
    }
    return 0;
}



