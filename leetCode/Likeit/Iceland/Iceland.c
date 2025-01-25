#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ROW 7;
#define COL 7;

/*
 * cheak for the iceland :
 * 
 * */


void removeIsland(int matrix[ROW][COL],int size){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(is_valid(matrix,i,j)){

            }
        }
    }
}

void printGrid(int matrix[ROW][COL]){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int matrix [ROW][COL] = 
    {
        {1,0,0,0,0,0},
        {0,0,0,1,1,1},
        {0,0,0,0,1,0},
        {1,1,0,0,1,0},
        {1,0,1,1,0,0},
        {1,0,0,0,0,1},
    };
    printf("Original Grid:\n");
    printGrid(matrix);
    removeIsland(matrix, threshold);
    printf("Grid after removing islands :\n");
    printGrid(matrix);
    rreturn 0;
}
