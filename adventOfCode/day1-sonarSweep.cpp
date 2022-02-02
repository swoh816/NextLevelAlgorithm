#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

// PART 1
// #define STRLEN 256
// int incCnt;
// int main()
// {
//     FILE *pFile = fopen("./input.txt", "r");
//     char string[STRLEN];
//     fgets(string, STRLEN, pFile);
//     int oldInt = atoi(string);
    
//     int newInt;
//     while(fgets(string, STRLEN, pFile) != NULL)
//     {
//         newInt = atoi(string);
//         if (newInt > oldInt)
//         {
//             ++incCnt;
//         }
//         oldInt = newInt;
//     }
//     printf("%d", incCnt);
// }


// PART 2
#define STRLEN 256

int incCnt;
int sumPrev, sumCurr;

int main()
{
    FILE *pFile = fopen("./input_day1.txt", "r");
    char string[STRLEN];
    int currIdx;
    int intWindow[3];
    int windowIdx = 3;

    for(int i=0; i<3; i++)
    {
        fgets(string, STRLEN, pFile);
        intWindow[i] = atoi(string);
        sumCurr += atoi(string);
    }
    sumPrev = sumCurr;
    currIdx = 0;
    
    while (fgets(string, STRLEN, pFile) != NULL)
    {
        sumCurr += atoi(string);
        sumCurr -= intWindow[currIdx];
        if (sumCurr > sumPrev)
        {
            // printf("%d\n", sumCurr);
            // printf("%d\n", sumPrev);
            ++incCnt;
        }
        sumPrev = sumCurr;
        intWindow[currIdx] = atoi(string);
        ++currIdx;
        currIdx %= 3;
    }
    printf("%d", incCnt);
}