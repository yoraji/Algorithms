#include "sudoku.h"


int main()
{
	int **puzzle;
	puzzle = makepuzzle();
	if(backtracking(puzzle,0,0)){
		printpuzzle(puzzle);
	}else
		printf("NO_FUCKING_CLEAR_SOLUTION");
	return 0;
}
