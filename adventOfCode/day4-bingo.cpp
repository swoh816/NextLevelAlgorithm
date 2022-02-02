#include <stdio.h>
#include <string.h>
#include <string>

#define CODE_LEN 1000

FILE *pFile = fopen("./input_day4.txt", "r");
char* pChar;

char codeChar[CODE_LEN];
int code[100];

int board[6][6];
int minRoundUntilEnd = 10000;
int maxRoundUntilEnd = 0;

int countUntilWin()
{
    // Initialize board
    for (int i=0; i<6; i++)
    {
        board[i][0] = 5;
        board[0][i] = 5;
    }

    // Insert input from text to board
    int rowIdx = 1;
    int colIdx;
    int sumRemaining = 0;
    while(rowIdx < 6)
    {
        colIdx = 1;
        fgets(codeChar, CODE_LEN, pFile);
        pChar = strtok(codeChar, " ");
        while(pChar != NULL)
        {
            board[rowIdx][colIdx] = atoi(pChar);
            sumRemaining += atoi(pChar);
            pChar = strtok(NULL, " ");
            ++colIdx;
        }
        ++rowIdx;
    }

    // Count the number of rounds until break
    int roundUntilEnd = 0;
    for (auto e : code)
    {
        for (int i=1; i<6; i++)
        {
            for (int j=1; j<6; j++)
            {
                if (board[i][j] == e)
                {
                    sumRemaining -= e;
                    board[i][j] = -1;
                    
                    board[0][j] -= 1;
                    board[i][0] -= 1;
                    if (board[0][j] == 0 || board[i][0] == 0)
                    {
                        // // PART1
                        // minRoundUntilEnd = roundUntilEnd;
                        // return sumRemaining*e;

                        // PART2
                        if (roundUntilEnd > maxRoundUntilEnd)
                        {
                            maxRoundUntilEnd = roundUntilEnd;
                            return sumRemaining*e;
                        }
                        else
                        {
                            return 0;
                        }
                    }
                }
            }
        }
        ++roundUntilEnd;
        // // PART1
        // if (roundUntilEnd > minRoundUntilEnd)
        // {
        //     return 0;
        // }
    }

    return 0;
}

int main()
{
    int codeCnt = 0;
    int score;
    int winningScore = 0;


    fgets(codeChar, CODE_LEN, pFile);
    pChar = strtok(codeChar, ",");
    while(pChar != NULL)
    {
        code[codeCnt] = atoi(pChar);
        pChar = strtok(NULL, ",");
        codeCnt++;
    }

    while(fgets(codeChar, CODE_LEN, pFile) != NULL)
    {
        score = countUntilWin();
        if (score != 0)
        {
            winningScore = score;
        }
    }
    printf("winningScore: %d", winningScore);

    return 0;
}