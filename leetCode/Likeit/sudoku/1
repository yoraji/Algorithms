#include "sudoku.h"

int **makepuzzle()
{
	int array[9][9]={0,7,1	,0,0,0	,4,3,0,
			8,0,0	,3,0,9	,0,0,6,
			0,0,5	,0,0,8	,0,0,2,
			1,9,3	,7,0,0	,2,8,0,
			0,0,0	,0,0,0	,0,0,0,
			0,4,6	,0,0,0	,9,1,0,
			7,0,0	,2,0,1	,0,0,4,
			0,0,8	,0,0,7	,0,0,9,
			6,3,2	,4,0,0	,8,7,0
	};
	int **puzzle;
	int i,j;
	puzzle = (int **)malloc(sizeof(int*)*9);
	for(i=0; i<9;i++){
		puzzle[i] = malloc(sizeof(int)*9);
		for(j=0;j<9;j++){
			puzzle[i][j] = array[i][j];	
		}
	}
	return puzzle;
}
int is_Valide(int **puzzle,int i,int j, int s)
{
	for(int n=0;n<9;n++){
		if(puzzle[i][n] == s)
		{
			return 0;
		}
	}

	for(int m=0; m<9;m++ ){
		if(puzzle[m][j] == s){
			return 0;
		}
	}
	int startRow = i - (i % 3);
	int startCol = j - (j % 3);
 	for (int a = 0; a < 3; a++) {
        	for (int b = 0; b < 3; b++) {
        	    if (puzzle[startRow + a][startCol + b] == s) {
             	 	  return 0;
            	    }
        	}
    	}
    	return 1;
}

int backtracking(int **puzzle,int i,int j){
	if(i==9){
		return 1;
	}
	if(j==9){
		return backtracking(puzzle,i+1,0);
	}
	if(puzzle[i][j] != 0){
		return backtracking(puzzle,i,j+1);
	}
	for(int p=1; p <= 9;p++)
	{
		if(is_Valide(puzzle,i,j,p)){
			puzzle[i][j] = p;
			if(backtracking(puzzle,i,j+1)){
				return 1;
			}
			puzzle[i][j]=0;
		}
	}
	return 0;
}

void	printpuzzle(int **puzzle)
{
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			printf(" %d ",puzzle[i][j]);
			if(((j+1) % 3) == 0 &&j != 8){
				printf("  ");
			}
		}
		printf("\n");
		if(((i+1)%3) == 0){
			printf("\n");
		}
	}
}
