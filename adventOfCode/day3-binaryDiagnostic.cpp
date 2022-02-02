#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>

#define NUMBER_OF_DIGITS    12
#define NUMBER_OF_TC    1000

int bits[6];
int bitSum[6];

int main()
{
    // PART1
    // freopen("./input_day3.txt", "r", stdin);

    // char binaryCodeString[NUMBER_OF_DIGITS + 2];
    // char gammaRateString[NUMBER_OF_DIGITS + 2];
    // char epsilonRateString[NUMBER_OF_DIGITS + 2];
    // int digitSum[NUMBER_OF_DIGITS] = {-500, -500, -500, -500, -500, -500, -500, -500, -500, -500, -500, -500};

    // FILE *pFile = fopen("./input_day3.txt", "r");
    // while(fgets(binaryCodeString, NUMBER_OF_DIGITS + 2, pFile) != NULL)
    // {
    //     // std::cout << "string version: " << binaryCodeString << std::endl;
    //     for (int i=0; i<NUMBER_OF_DIGITS; i++)
    //     {
    //         digitSum[i] += binaryCodeString[i] - 48;
    //     }
    // };

    // for (int i=0; i<NUMBER_OF_DIGITS; i++)
    // {
    //     if (digitSum[i] > 0)
    //     {
    //         gammaRateString[i] = '1';
    //         epsilonRateString[i] = '0';
    //     }
    //     else
    //     {
    //         gammaRateString[i] = '0';
    //         epsilonRateString[i] = '1';
    //     }
    // }

    // std::cout << gammaRateString << std::endl;
    // std::cout << epsilonRateString << std::endl;
    // int gammaRate = 0;
    // int epsilonRate = 0;
    // for (int i=0; i<NUMBER_OF_DIGITS; i++)
    // {
    //     gammaRate <<= 1;
    //     gammaRate += gammaRateString[i] - 48;
        
    //     epsilonRate <<= 1;
    //     epsilonRate += epsilonRateString[i] - 48;
    // }
    // std::cout << gammaRate*epsilonRate << std::endl;
    // std::cout << gammaRate << std::endl;
    // std::cout << epsilonRate << std::endl;
    

    // PART 2
    double binaries[NUMBER_OF_TC];
    int oxygenGenRating[NUMBER_OF_TC];
    int co2ScrubberRating[NUMBER_OF_TC];
    for (int i=0; i<NUMBER_OF_TC; i++)
    {
        oxygenGenRating[i] = i;
        co2ScrubberRating[i] = i;
    }

    freopen("./input_day3.txt", "r", stdin);
    for(int i=0; i<NUMBER_OF_TC; i++)
    {
        scanf("%lf", &binaries[i]);
    }


    int oxygenGenCnt = NUMBER_OF_TC;
    int oxygenGenIdx;
    int newOxygenGenIdx;
    double removeHigherDigit;

    int dominantBit;
    for (int exponent=11; exponent>=0; --exponent)
    {
        // Investigate dominant bit
        oxygenGenIdx = 0;
        dominantBit = 0;
        removeHigherDigit = ((int)(binaries[oxygenGenRating[0]]/(pow(10,exponent+1))))*pow(10,exponent+1);
        while (oxygenGenIdx != oxygenGenCnt)
        {
            dominantBit += (int)((binaries[oxygenGenRating[oxygenGenIdx]] - removeHigherDigit)/(pow(10,exponent)));
            ++oxygenGenIdx;
        }
        dominantBit = (int)((2*dominantBit/oxygenGenCnt)) >= 1 ? 1 : 0;

        // Filter valid oxygenRatings and their count
        newOxygenGenIdx = 0;
        oxygenGenIdx = 0;
        while (oxygenGenIdx != oxygenGenCnt)
        {
            // printf("binaries[oxygenGenRating[newOxygenGenIdx]]/(pow(10,exponent)): %lf\n", binaries[oxygenGenRating[newOxygenGenIdx]]/(pow(10,exponent)));
            if ((int)((binaries[oxygenGenRating[oxygenGenIdx]] - removeHigherDigit)/(pow(10,exponent))) == dominantBit)
            {
                oxygenGenRating[newOxygenGenIdx] = oxygenGenRating[oxygenGenIdx];
                ++newOxygenGenIdx;
            }
            ++oxygenGenIdx;
        }
        oxygenGenCnt = newOxygenGenIdx;
        oxygenGenRating[oxygenGenCnt] = -1; // Just for marking the end of array
        if (oxygenGenCnt == 1)
        {
            printf("%lf\n", binaries[oxygenGenRating[0]]);
            break;
        }
    }


    int co2ScrubberCnt = NUMBER_OF_TC;
    int co2ScrubberIdx;
    int newCo2ScrubberIdx;
    int minorityBit;
    for (int exponent=11; exponent>0; exponent--)
    {
        co2ScrubberIdx = 0;
        minorityBit = 0;
        removeHigherDigit = ((int)(binaries[co2ScrubberRating[co2ScrubberIdx]]/pow(10, exponent+1)))*pow(10, exponent+1);
        while (co2ScrubberIdx != co2ScrubberCnt)
        {
            minorityBit += (int)((binaries[co2ScrubberRating[co2ScrubberIdx]] - removeHigherDigit)/pow(10, exponent));
            ++co2ScrubberIdx;
        }
        minorityBit = (2*minorityBit)/co2ScrubberCnt < 1 ? 1 : 0;

        co2ScrubberIdx = 0;
        newCo2ScrubberIdx = 0;
        while (co2ScrubberIdx != co2ScrubberCnt)
        {
            if ((int)((binaries[co2ScrubberRating[co2ScrubberIdx]] - removeHigherDigit)/pow(10, exponent)) == minorityBit)
            {
                co2ScrubberRating[newCo2ScrubberIdx] = co2ScrubberRating[co2ScrubberIdx];
                ++newCo2ScrubberIdx;
            }
            ++co2ScrubberIdx;
        }
        co2ScrubberCnt = newCo2ScrubberIdx;
        co2ScrubberRating[co2ScrubberCnt] = -1;
        if (co2ScrubberCnt == 1)
        {
            printf("%lf\n", binaries[co2ScrubberRating[0]]);
            break;
        }

    }

    // for (int i=0; i<NUMBER_OF_DIGITS; i++)
    // {
    //     binaryCodeString
    // }

    return 0;
}