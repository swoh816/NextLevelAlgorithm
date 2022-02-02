#include <stdio.h>
#include <malloc.h>

// Search zero from (0,0) to (N, N), and from (N, N) to (0, 0).
int** updateMatrix(int** mat, int matSize, int* matColSize){
    int** result = (int**)malloc(sizeof(int)*matSize*(*matColSize));
    // Initialize result
    for(int i=0; i<matSize; i++)
    {
        for (int j=0; j<*matColSize; j++)
        {
            result[i][j] = 300;
        }
    }

    // Down right, 0 0 1 1
    for (int i=0; i<matSize; i++)
    {
        for (int j=0; j<*matColSize; j++)
        {
            if (mat[i][j] != 0)
            {
                if (i == 0)
                {
                    if (result[i-1][j] < 300)
                    {
                        result[i][j] = result[i-1][j] + 1;
                    }
                }
                else if (j == 0)
                {
                    if (result[i][j-1] < 300)
                    {
                        result[i][j] = result[i][j-1] + 1;
                    }
                }
                else
                {
                    result[i][j] = result[i-1][j] + 1 > result[i][j-1] + 1 ? result[i-1][j] + 1 : result[i][j-1] + 1; 
                }
            }
            else
            {
                result[i][j] = 0;
            }
        }
    }

    // Upleft m-1 m-1
    for (int i=matSize-1; i>=0; i--)
    {
        for (int j=*matColSize-1; j>=0; j++)
        {
            if (mat[i][j] != 0)
            {
                if (i == matSize-1)
                {
                    if (result[i+1][j] < 300)
                    {
                        result[i][j] = result[i+1][j] + 1;
                    }
                }
                else if (j == *matColSize-1)
                {
                    if (result[i][j+1] < 300)
                    {
                        result[i][j] = result[i][j+1] + 1;
                    }
                }
                else
                {
                    result[i][j] = result[i+1][j] + 1 > result[i][j+1] + 1 ? result[i+1][j] + 1 : result[i][j+1] + 1; 
                }
            }
        }
    }
    return result;
}


int main()
{
    int matrix[3][3] = {{0,0,0},{0,1,0},{0,0,0}};
    int** mat = matrix;
    int matSize = 3;
    int* matColSize = &matSize;
    updateMatrix(mat, matSize, matColSize);
}