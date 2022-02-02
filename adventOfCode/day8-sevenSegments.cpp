#include <stdio.h>
#include <string.h>
#include <iostream>

#define INPUT_STRING_SIZE 100
FILE *pFile = fopen("input_day8.txt", "r");
char inputString[INPUT_STRING_SIZE];

// Function used for PART 2
void oneHotVector(int num, int outputCnt, char* characterPtrArr, char oneHotVectorArr[][])
{
    for(int i=0; i<outputCnt; i++) oneHotVectorArr[num][i] = 1;
}

int main()
{
    char* pCharInput;
    char* pCharOutput;
    char* pCharInputOneByOne;
    char* pCharOutputOneByOne;

    int inputCnt;
    int outputCnt;

    // PART 1
    int uniqueOutputCnt = 0;
    while (fgets(inputString, INPUT_STRING_SIZE, pFile) != NULL)
    {
        pCharInput = strtok(inputString, "|");
        pCharOutput = strtok(NULL, "|");

        // PART 1
        pCharOutput = strtok(pCharOutput, " ");
        while (pCharOutput != NULL)
        {
            // printf("%s\n", pCharOutput);
            outputCnt = 0;
            while (*(pCharOutput + outputCnt) != NULL
                    && *(pCharOutput + outputCnt) != '\n')
                ++outputCnt;

            if (outputCnt == 2 || outputCnt == 4 || outputCnt == 3 || outputCnt == 7)
                ++uniqueOutputCnt;
            pCharOutput = strtok(NULL, " ");
        }
    }
    printf("PART1 ANSWER: uniqueOutputCnt: %d\n", uniqueOutputCnt);




    // PART 2
    char oneHotVectorArr[10][7];

    pFile = fopen("input_day8.txt", "r");
    while (fgets(inputString, INPUT_STRING_SIZE, pFile) != NULL)
    {
        // 0. Initialize characterArr
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<7; j++) oneHotVectorArr[i][j] = 0;
        }
        pCharInput = strtok(inputString, "|");
        pCharOutput = strtok(NULL, "|");
        test text

        // 1. Find numbers with unique number of segments
        pCharInputOneByOne = strtok(pCharInput, " ");
        while (pCharInputOneByOne != NULL)
        {
            while (*(pCharInput + inputCnt) != NULL) ++inputCnt;

            if (outputCnt == 2) {
                oneHotVector(1, outputCnt, pCharInput, oneHotVectorArr);
            } else if(outputCnt == 4) {
                oneHotVector(4, outputCnt, pCharInput, oneHotVectorArr);
            } else if(outputCnt == 3) {
                oneHotVector(7, outputCnt, pCharInput, oneHotVectorArr);
            } else if(outputCnt == 7) {
                oneHotVector(8, outputCnt, pCharInput, oneHotVectorArr);
            }
            pCharInput = strtok(NULL, " ");
        }

        // 2. Find all other numbers
        pCharInputOneByOne = strtok(pCharInput, " ");
        while (pCharInputOneByOne != NULL)
        {
            // printf("%s\n", pCharInput);
            while (*(pCharInput + inputCnt) != NULL)
            {
                ++inputCnt;
            }

            if (inputCnt == 5) // 3, 2, 5
            {
                // if x has 1: 3
                // if x and 4 share 3 segments: 5
                // if x and 4 share 2 segments: 2
            }
            else if (inputCnt == 6) // 0, 6, 9
            {
                // if x has 1 and 4: 9
                // if x has 1 but not 4: 0
                // otherwise: 6
            }
            pCharInput = strtok(NULL, " ");
        }

        pCharOutput = strtok(pCharOutput, " ");
        while (pCharOutput != NULL)
        {
            // printf("%s\n", pCharOutput);
            outputCnt = 0;
            while (*(pCharOutput + outputCnt) != NULL
                    && *(pCharOutput + outputCnt) != '\n')
            {
                ++outputCnt;
            }

            if (outputCnt == 2 || outputCnt == 4 || outputCnt == 3 || outputCnt == 7)
            {
                ++uniqueOutputCnt;
            }
            pCharOutput = strtok(NULL, " ");
        }
    }
    return 