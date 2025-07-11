#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int result = 0;
    for(int i=0;i<gridSize;i++)
    {
        int word = gridColSize[i];
        for(int j=0;j < word;j++)
        {
            if(grid[i][j] == 1)
            {
                result += 4;
                if(j + 1 < word && grid[i][j + 1] == 1)
                    result -= 1;
                if(j > 0 && grid[i][j - 1] == 1)
                    result -= 1;
                if(i + 1  < gridSize && grid[i+1][j] == 1)
                    result -= 1;
                if(i > 0 && grid[i-1][j] == 1)
                    result -= 1;
            }
        }
    }
    return result;
}

int main() {
    int gridSize = 4;
    int gridColSize[] = {4, 4, 4, 4};
    int* grid[4];
    
    int row1[] = {0, 1, 0, 0};
    int row2[] = {1, 1, 1, 0};
    int row3[] = {0, 0, 0, 1};
    int row4[] = {0, 1, 0, 0};

    grid[0] = row1;
    grid[1] = row2;
    grid[2] = row3;
    grid[3] = row4;

    printf("Island Perimeter: %d\n", islandPerimeter(grid, gridSize, gridColSize));
    return 0;
}
