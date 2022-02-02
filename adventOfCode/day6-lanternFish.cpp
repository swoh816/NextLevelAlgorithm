#include <stdio.h>
#include <string.h>
#include <string>
#include <cmath>
#include <iostream>

#define STRLEN 1000
char inputString[STRLEN];
typedef unsigned long long ull;

FILE *pFile = fopen("input_day6.txt", "r");

ull numberOfOffsprings(int from, int to)
{
    // A new offspring reproduces every 7 days starting from `from`
    int numberOfReproduction = ceil((to - from)/7);

    // Total number of offsprings from the current fish.
    ull result=numberOfReproduction;

    for (int i=1; i<=numberOfReproduction; i++)
    {
        // Born after 7*i days
        result += numberOfOffsprings((from + 2) + 7*i, to);
    }

    return result;
}

int main()
{
    fgets(inputString, STRLEN, pFile);
    ull totalCnt = 0;
    int numberOfDays = 256;

    // Solution 1
    // char* pChar;
    // pChar = strtok(inputString, ",");
    // while (pChar != NULL)
    // {
    //     // std::cout << atoi(pChar) << std::endl;
    //     totalCnt += 1 + numberOfOffsprings(atoi(pChar) - 6, numberOfDays);
    //     pChar = strtok(NULL, ",");
    // }

    // Solution 2
    ull totalOffspringPerRemainingDate[7];
    for (int i=0; i<7; i++)
    {
        totalOffspringPerRemainingDate[i] = 1 + numberOfOffsprings(i - 6, numberOfDays);
    }

    ull lanternFishCntPerRemainingDate[7] = {0, 0, 0, 0, 0, 0, 0};
    char* pChar;
    pChar = strtok(inputString, ",");
    while(pChar != NULL)
    {
        lanternFishCntPerRemainingDate[atoi(pChar)]++;
        pChar = strtok(NULL, ",");
    }

    for (int i=0; i<7; i++)
    {
        totalCnt += lanternFishCntPerRemainingDate[i]*totalOffspringPerRemainingDate[i];
    }

    // Answer
    std::cout << "totalCnt: " << totalCnt << std::endl;
    return 0;
}