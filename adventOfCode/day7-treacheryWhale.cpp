#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <cmath>

#define STRLEN 100000
char inputStr[STRLEN];
int crabLoc[1000];

FILE *pFile = fopen("./input_day7.txt", "r");

int main()
{
    char* pChar;
    fgets(inputStr, STRLEN, pFile);
    pChar = strtok(inputStr, ",");
    int crabLocCnt = 0;
    int crabLocIdxSum = 0;
    while(pChar != NULL)
    {
        crabLoc[crabLocCnt] = atoi(pChar);
        crabLocIdxSum += atoi(pChar);
        pChar = strtok(NULL, ",");
        ++crabLocCnt;
    }
    printf("Crab count: %d\n", crabLocCnt);

    // PART 1
    std::sort(&crabLoc[0], &crabLoc[crabLocCnt-1]);
    int minStepLoc1 = crabLoc[crabLocCnt/2];
    printf("MinStepLoc1: %d\n", minStepLoc1);
    int minStepLoc2 = crabLoc[crabLocCnt/2-1];
    printf("MinStepLoc2: %d\n", minStepLoc2);

    int totalFuelCost = 0;
    for (int i=0; i<crabLocCnt; i++)
    {
        totalFuelCost += abs(crabLoc[i] - crabLoc[crabLocCnt/2-2]);
    }
    printf("totalFuelCost: %d\n", totalFuelCost);
    printf("crabLocIdxSum: %d\n", crabLocIdxSum);
    printf("\n");

    
    // PART2
    int meanIdx = crabLocIdxSum/crabLocCnt;
    printf("MeanIdx: %d\n", meanIdx);
    int ceilMeanIdx = ceil((double)crabLocIdxSum/(double)crabLocCnt);
    printf("ceil(MeanIdx): %d\n", ceilMeanIdx);
    int plusMeanIdx = crabLocIdxSum/crabLocCnt + 1;
    printf("Plus MeanIdx: %d\n", plusMeanIdx);
    int roundedMeanIdx = round((double)crabLocIdxSum/(double)crabLocCnt);
    printf("roundedMeanIdx MeanIdx: %d\n", roundedMeanIdx);

    totalFuelCost = 0;
    for (int i=0; i<crabLocCnt; i++)
    {
        totalFuelCost += abs(crabLoc[i] - ceilMeanIdx)*(abs(crabLoc[i] - ceilMeanIdx) + 1)/2;
        // printf("%d\n", abs(crabLoc[i] - crabLocIdxSum/crabLocCnt));
    }
    printf("totalFuelCost: %d", totalFuelCost);
}