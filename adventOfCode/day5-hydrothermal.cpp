#include <stdio.h>
#include <string.h>
#include <string>

#define STRLEN 20
char inputString[STRLEN];
int oceanFloor[1000][1000];

FILE *pFile = fopen("input_day5.txt", "r");

int main()
{
    char crd;
    char* cStartCrd;
    char* cEndCrd;
    int nStartCrd[2];
    int nEndCrd[2];

    int nSmallerCrd;
    int nLargerCrd;

    int nSmallerXCrd;
    int nSmallerYCrd;
    int nLargerXCrd;
    int nLargerYCrd;

    while (fgets(inputString, STRLEN, pFile) != NULL)
    {
        cStartCrd = strtok(inputString, "->");
        cEndCrd = strtok(NULL, "->");

        // PART1: only consider horizontal/vertical vents
        nStartCrd[0] = atoi(strtok(cStartCrd, ","));
        nStartCrd[1] = atoi(strtok(NULL, ","));
        nEndCrd[0] = atoi(strtok(cEndCrd, ","));
        nEndCrd[1] = atoi(strtok(NULL, ","));
        // If vertical
        if (nStartCrd[0] == nEndCrd[0])
        {
            nSmallerCrd = nStartCrd[1] < nEndCrd[1] ? nStartCrd[1] : nEndCrd[1];
            nLargerCrd = nStartCrd[1] > nEndCrd[1] ? nStartCrd[1] : nEndCrd[1];
            for (int i=nSmallerCrd; i<=nLargerCrd; i++)
            {
                oceanFloor[nStartCrd[0]][i] += 1;
            }
        }
        // If horizontal
        else if (nStartCrd[1] == nEndCrd[1])
        {
            nSmallerCrd = nStartCrd[0] < nEndCrd[0] ? nStartCrd[0] : nEndCrd[0];
            nLargerCrd = nStartCrd[0] > nEndCrd[0] ? nStartCrd[0] : nEndCrd[0];
            for (int i=nSmallerCrd; i<=nLargerCrd; i++)
            {
                oceanFloor[i][nStartCrd[1]] += 1;
            }
        }
        // PART2: If diagnoal
        else
        {
            nSmallerXCrd = nStartCrd[0] < nEndCrd[0] ? nStartCrd[0] : nEndCrd[0];
            nLargerXCrd = nStartCrd[0] > nEndCrd[0] ? nStartCrd[0] : nEndCrd[0];
            nSmallerYCrd = nStartCrd[1] < nEndCrd[1] ? nStartCrd[1] : nEndCrd[1];
            nLargerYCrd = nStartCrd[1] > nEndCrd[1] ? nStartCrd[1] : nEndCrd[1];
            // Lower left to higher right
            if ((nSmallerXCrd == nStartCrd[0] && nSmallerYCrd == nStartCrd[1]) ||
            (nSmallerXCrd == nEndCrd[0] && nSmallerYCrd == nEndCrd[1]))
            {
                while(nSmallerXCrd <= nLargerXCrd)
                {
                    oceanFloor[nSmallerXCrd][nSmallerYCrd] += 1;
                    ++nSmallerXCrd;
                    ++nSmallerYCrd;
                }
            }
            // higher left to lower right
            else
            {
                while(nSmallerXCrd <= nLargerXCrd)
                {
                    oceanFloor[nSmallerXCrd][nLargerYCrd] += 1;
                    ++nSmallerXCrd;
                    --nLargerYCrd;
                }
            }
        }
    };

    int nOverlapCnt = 0;
    for (int i=0; i<1000; i++)
    {
        for (int j=0; j<1000; j++)
        {
            if(oceanFloor[i][j] > 1)
            {
                ++nOverlapCnt;
            }
        }
    }
    printf("Overlap cnt: %d", nOverlapCnt);
    return 0;
}