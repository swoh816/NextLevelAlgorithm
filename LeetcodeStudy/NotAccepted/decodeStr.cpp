#include <stdio.h>

char resultStr[31];
int resultIdx;
char numStr[4];
int stack[31][2]; // {{repeat1, resultIdx1}, {repeat2, resultIdx2}, ...}
int (*stackPtr)[2] = stack;

int convertStrToInt(char* numStrPtr)
{
    int resultInt = 0;
    while(*numStrPtr != '\0')
    {
        resultInt *= 10;
        resultInt += (int)(*numStrPtr)-(int)('0');
        numStrPtr++;
    }
    return resultInt;
}

int isNumber(char* s)
{
    return (int)('0') <= (int)(*s) && (int)(*s) <= (int)('9');
}

void pushStack(int repeat, int resultStrIdx)
{
    (*stackPtr)[0] = repeat;
    (*stackPtr)[1] = resultStrIdx;
    // *(*stackPtr+0) = repeat;
    // *(*stackPtr+1) = resultStrIdx;
    stackPtr++;
}

char* decodeString(char* s)
{
    int sIdx = 0;
    stackPtr = stack;
    resultIdx = 0;
    while (s[sIdx] != '\0'){
        // 1. If encounter number, enter stack
        // 1.1. Add number stack
        if (isNumber(&s[sIdx]))
        {
            int resultInt = 0;
            int numIdx = 0;
            do{
                numStr[numIdx] = s[sIdx]; // ex) 32 -> numStr = {'3', '2'}, numIdx = 2
                numIdx++;
                sIdx++;
            }while(isNumber(&s[sIdx]));
            resultInt = convertStrToInt(numStr);
            sIdx++; // skip character [
            pushStack(resultInt, resultIdx);
        }
        else
        {
            // 1.2. Add character stack
            if (s[sIdx] == ']')
            {
                do{
                    // Pop stack
                    int iterResultIdx = resultIdx; // Or can i just use resultIdx?? NO!!!!
                    for (int i=0; i<*(stackPtr-1)[0]-1; i++) // For i in range(repeat-1). Minus one because you've already printed once
                    {
                        // from *stackPtr[1] to resultIdx;
                        for (int j=0; j<iterResultIdx-*(*(stackPtr-1)+1); j++)
                        {
                            resultStr[resultIdx] = resultStr[*(*(stackPtr-1)+1)+j]; // add
                            resultIdx++;
                        }
                    }
                    stackPtr--;
                    sIdx++; // skip ']'
                    break;
                }while(!isNumber(&s[sIdx]));
            }
            else{
                resultStr[resultIdx] = s[sIdx];
                resultIdx++;
                sIdx++;
            }
        }
        // if stack is not empty, add to stack;
    }
    resultStr[resultIdx] = '\0';
    return resultStr;
}

int main()
{
    char testStr[] = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    char* resultStr;
    resultStr = decodeString(testStr);
    printf("%s", resultStr);
    // printf("Hello");
    // convertStrToInt(char* numStr, int numSize)
    return 0;
}
            // currStrIdx = &s[sIdx]-s; // Why not divide by sizeof(*char)?
            // lastStrIdx = currStrIdx;