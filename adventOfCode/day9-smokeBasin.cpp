#include <stdio.h>
#include <string.h>

#define ROW_SIZE 100
#define COL_SIZE 100

int volcanicHell[ROW_SIZE+2][COL_SIZE+2];
int sumRiskLevel;

int visited[ROW_SIZE+2][COL_SIZE+2];
int sumBasinSizes;
int threeLargestBasins[3];
int basinSize;

void bfs(int rowIdx, int colIdx)
{
    if(volcanicHell[rowIdx][colIdx] < 9 && visited[rowIdx][colIdx] == 0)
    {
        ++basinSize;
        visited[rowIdx][colIdx] = 1;
        for (int i=-1; i<=1; i+=2)
        {
            if (volcanicHell[rowIdx][colIdx] < volcanicHell[rowIdx+i][colIdx])
            {
                bfs(rowIdx+i, colIdx);
            }
            if (volcanicHell[rowIdx][colIdx] < volcanicHell[rowIdx][colIdx+i])
            {
                bfs(rowIdx, colIdx+i);
            }
        }
    }
}

int main()
{
    for (int i=0; i<ROW_SIZE+2; i++)
    {
        volcanicHell[0][i] = 10;
        volcanicHell[ROW_SIZE+1][i] = 10;
        volcanicHell[i][0] = 10;
        volcanicHell[i][COL_SIZE+1] = 10;

        visited[0][i] = 1;
        visited[ROW_SIZE+1][i] = 1;
        visited[i][0] = 1;
        visited[i][COL_SIZE+1] = 1;
    }

    freopen("./input_day90.txt", "r", stdin);
    for(int i=1; i<=ROW_SIZE; i++)
    {
        for(int j=1; j<=COL_SIZE; j++)
        {
            scanf("%d", &volcanicHell[i][j]);
        }
    }


    // PART1: sumRiskLevel
    // for(int i=1; i<=COL_SIZE; i++)
    // {
    //     for(int j=1; j<=COL_SIZE; j++)
    //     {
    //         if (volcanicHell[i][j] < volcanicHell[i-1][j] && volcanicHell[i][j] < volcanicHell[i+1][j]
    //         && volcanicHell[i][j] < volcanicHell[i][j-1] && volcanicHell[i][j] < volcanicHell[i][j+1])
    //         {
    //             sumRiskLevel += volcanicHell[i][j] + 1;
    //         }
    //     }
    // }
    // printf("%d", sumRiskLevel);


    // PART2: sumRiskLevel
    for(int i=1; i<=ROW_SIZE; i++)
    {
        for(int j=1; j<=COL_SIZE; j++)
        {
            if (visited[i][j] != 1)
            {
                if (volcanicHell[i][j] < volcanicHell[i-1][j] && volcanicHell[i][j] < volcanicHell[i+1][j]
                && volcanicHell[i][j] < volcanicHell[i][j-1] && volcanicHell[i][j] < volcanicHell[i][j+1])
                {
                    // printf("%d %d\n", i, j);
                    basinSize = 0;
                    bfs(i, j);
                    for (int i=0; i<3; i++)
                    {
                        if (threeLargestBasins[i] < basinSize)
                        {
                            threeLargestBasins[i] = basinSize;
                            break;
                        }
                    }
                    // if (basinSize > threeLargestBasins[0])
                    // {
                    //     printf("%d %d %d\n", i, j, basinSize);
                    //     threeLargestBasins[2] = threeLargestBasins[1];
                    //     threeLargestBasins[1] = threeLargestBasins[0];
                    //     threeLargestBasins[0] = basinSize;
                    // }
                }
            }
        }
    }
    
    for (int i=0; i<3; i++)
    {
        printf("%d ", threeLargestBasins[i]);
    }
    printf("\n");

    for (int i=1; i<3; i++)
    {
        threeLargestBasins[i] *= threeLargestBasins[i-1];
    }
    printf("%d", threeLargestBasins[2]);

    // FILE *pFile = fopen("./input_day9.txt", "r");
    // while(fgets(string, STRLEN, pFile) != NULL)
    // {
    //     printf("%s", string);
    // }
    // fgets(string, STRLEN, pFile);

    return 0;
}