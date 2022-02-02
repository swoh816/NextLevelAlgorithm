#include <stdio.h>
// 
// char* pPtr;
// char* sPtr;
// char prevStr;
// 
// bool isMatch(char * s, char * p){
//     sPtr = s;
//     pPtr = p;
//     while(*pPtr != 0 && *sPtr != 0)
//     {
//         if (*pPtr == '*')
//         {
//             while(*sPtr == prevStr)
//             {
//                 ++sPtr;
//             }
//             ++pPtr;
//             continue;
//         }
//         else if (*pPtr == '.')
//         {
//             // welcome any string
//         }
//         else
//         {
//             if (*sPtr != *pPtr)
//             {
//                 return false;
//             }
//         }
//         prevStr = *sPtr;
//         ++sPtr;
//         ++pPtr;        
//     }
//     
//     if (*sPtr != 0)
//     {
//         return false;
//     }
//     return true;
// }

// Heap overflow may occur if p string is longer
// sPtr++ twice in line 37 and 20 (continue?)




// char* pPtr;
// char* sPtr;

// bool isMatch(char * s, char * p){
//     sPtr = s;
//     pPtr = p;

//     // Continue until finish reading string (s)
//     while(*sPtr != 0)
//     {
//         // If there are remaining strings but no remaining pattern (p), return false
//         if (*pPtr == 0)
//         {
//             return false;
//         }
//         printf("1\n");
//         printf("Current sPtr: %c\n", *sPtr);
//         printf("Current pPtr: %c\n", *pPtr);
//         if (*(pPtr+1) == '*')
//         {
//             printf("sPtr1: %c\n", *sPtr);
//             while(*sPtr == *pPtr)
//             {
//                 printf("In first while loop\n");
//                 ++sPtr;
//                 printf("sPtr: %c\n", *sPtr);
//                 if (*sPtr == 0)
//                 {
//                     if (*(pPtr+2) == 0)
//                     {
//                         return true;
//                     }
//                     else
//                     {
//                         while (*(pPtr+3) == '*')
//                         {
//                             pPtr = pPtr + 2;
//                             printf("pPtr in while loop: %c\n", *pPtr);
//                         }
//                         pPtr = pPtr + 2;
//                         if (*pPtr == *(sPtr-1))
//                         {
//                             return true;
//                         }
//                         return false;
//                     }
//                 }
//             }
//             if(*pPtr == '.')
//             {
//                 printf("In for loop\n");
//                 while(*(sPtr) != *(pPtr+2))
//                 {
//                     printf("*sPtr: %c\n", *sPtr);
//                     printf("*(pPtr+2): %c\n", *(pPtr+2));
//                     printf("In second while loop\n");
//                     ++sPtr;
//                     if (*sPtr == 0)
//                     {
//                         break;
//                     }
//                 }
//                 if (*(pPtr+2) == 0)
//                 {
//                     return true;
//                 }
//                 else
//                 {
//                     return false;
//                 }
//             }
//             pPtr = pPtr + 2;
//             continue;
//         }
//         else if (*pPtr == '.')
//         {
//         }
//         else
//         {
//             if (*sPtr != *pPtr)
//             {
//                 return false;
//             }
//         }
//         ++sPtr;
//         ++pPtr;
//         printf("After sPtr: %c\n", *sPtr);
//         printf("After pPtr: %c\n", *pPtr);
//     }


//     // Finished reading string but not finished reading pattern
//     if (*pPtr != 0)
//     {
//         // Read if all patterns following are useless
//         while (*(pPtr+1) == '*')
//         {
//             pPtr = pPtr + 2;
//             if (*pPtr == 0)
//             {
//                 break;
//             }
//         }
//         if(*pPtr != 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }



// char* pPtr;
// char* sPtr;
// 
// bool isMatch(char * s, char * p){
    // pPtr = p;
    // sPtr = s;
    // while(*pPtr != 0)
    // {
        // ++pPtr;
    // }
    // while(*sPtr != 0)
    // {
        // ++sPtr;
    // }
    // --pPtr;
    // --sPtr;
// 
    // while (true)
    // {
        // printf("*pPtr: %c\t", *pPtr);
        // printf("*sPtr: %c\n", *sPtr);
        // if (*pPtr == '*')
        // {
            // --pPtr;
            // if (*pPtr == '.')
            // {
                // if (pPtr == p)
                // {
                    // return true;
                // }
                // else
                // {
                    // --pPtr;
                    // while (*pPtr != *sPtr)
                    // {
                        // --sPtr;
                    // }
                // }
            // }
            // else
            // {
                // while(*pPtr == *sPtr && sPtr != s)
                // {
                    // printf("*sPtr inside loop: %c\n", *sPtr);
                    // --sPtr;
                // }
                // if (pPtr == p)
                // {
                    // if (sPtr == s)
                    // {
                        // if (*sPtr == *pPtr)
                        // {
                            // return true;
                        // }
                    // }
                    // else
                    // {
                        // return false;
                    // }
                // }
                // --pPtr;
            // }
            // If pPtr reaches the beginning of p
            // if (pPtr == p)
            // {
                // break;
            // }
        // }
        // else if (*pPtr == '.')
        // {
            // --sPtr;
            // --pPtr;
        // }
        // else
        // {
            // printf("*pPtr 2: %c\n", *pPtr);
            // if (*pPtr != *sPtr)
            // {
                // return false;
            // }
            // else if(pPtr == p)
            // {
                // if (sPtr == s)
                // {
                    // return true;
                // }
                // else
                // {
                    // return false;
                // }
            // }
            // --sPtr;
            // --pPtr;
        // }
// 
        // if(pPtr == p)
        // {
            // If you reach the beginning of string
            // if (sPtr == s)
            // {
                // if (*sPtr != *pPtr)
                // {
                    // return false;
                // }
            // }
            // In case you reach the beginning of pattern but not the beginning of string
            // else
            // {
                // char* dummySPtr = s;
                // char* dummyPPtr = p;
                // while(dummySPtr != sPtr+1)
                // {
                    // if(*dummySPtr != *dummyPPtr)
                    // {
                        // return false;
                    // }
                    // ++dummySPtr;
                    // ++dummyPPtr;
                // }
            // }
        // }
    // }
    // return true;
// }




char* pPtr;
char* sPtr;
int pPtrOffset;
int numOfRemainigPattern;

bool checkMatch(char *s, char* p)
{
    if (*p == '.')
    {
       return true;
    }
    else
    {
        if (*s == *p)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

// bool isMatch(char * s, char * p){
//     sPtr = s;
//     pPtr = p;

//     // Continue until finish reading string (s)
//     while(*sPtr != 0)
//     {
//         // If there are remaining strings but no remaining pattern (p), return false
//         if (*pPtr == 0)
//         {
//             return false;
//         }
//         printf("Current sPtr: %c\n", *sPtr);
//         printf("Current pPtr: %c\n", *pPtr);
//         if (*pPtr == '*')
//         {
//             // In case the length of repeated string is shorter than the length of repeated string in pattern (aaa/a*aaaaa)
//             // In case the length of repeated string is shorter than the length of repeated string in pattern (aaa/a*aaaaa)
//             pPtrOffset = 1;
//             while(*(pPtr+pPtrOffset) == *(pPtr-1))
//             {
//                 if (*sPtr == *(pPtr+pPtrOffset))
//                 {
//                     ++sPtr;
//                     ++pPtrOffset;
//                 }
//                 else
//                 {
//                     return false;
//                 }
//             }

//             while (checkMatch(sPtr, pPtr-1))
//             {
//                 ++sPtr;
//                 if (*sPtr == 0)
//                 {
//                     break;
//                 }
//             }

//             pPtr = pPtr + pPtrOffset;
//             continue;
//         }
//         else if (*pPtr == '.')
//         {
//         }
//         else
//         {
//             if (*sPtr != *pPtr)
//             {
//                 if (*(pPtr+1) == '*')
//                 {
//                     ++pPtr;
//                     continue;
//                 }
//                 else
//                 {
//                     return false;
//                 }
//             }
//         }
//         ++sPtr;
//         ++pPtr;
//     }


//     // Finished reading string but not finished reading pattern
//     if (*pPtr != 0)
//     {
//         // Read if all patterns following are useless
//         while (*(pPtr+1) == '*')
//         {
//             pPtr = pPtr + 2;
//             if (*pPtr == 0)
//             {
//                 break;
//             }
//         }

//         numOfRemainigPattern = 0;
//         while (*pPtr != 0)
//         {
//             ++numOfRemainigPattern;
//             ++pPtr;
//         }
//         sPtr = sPtr - numOfRemainigPattern;
//         while(*pPtr == *sPtr)
//         {
//             ++pPtr;
//             ++sPtr;
//         }

//         if (*pPtr != 0 || *sPtr != 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

char charQueue[16];
int head;
int tail;
char poppedChar;

bool isEmpty()
{
    return head == tail;
}

bool isFull()
{
    return head == tail + 1;
}

void pushQueue(char a)
{
    charQueue[tail] = a;
    ++tail;
    if (tail == 15)
    {
        tail = 0;
    }
}

char popQueue()
{
    char returnValue = charQueue[head];
    ++head;
    if (head == 15)
    {
        head = 0;
    }
    return returnValue;
}

bool isMatch(char * s, char * p){
    sPtr = s;
    pPtr = p;

    // Continue until finish reading string (s)
    while(*sPtr != 0)
    {
        // If there are remaining strings but no remaining pattern (p), return false
        if (*pPtr == 0)
        {
            return false;
        }
        printf("Current sPtr: %c\n", *sPtr);
        printf("Current pPtr: %c\n", *pPtr);
        if (*(pPtr+1) == '*')
        {
            while (*(pPtr+1) == '*')
            {
                // Push stack
                pushQueue(*pPtr);
                pPtr = pPtr + 2;
            }
            poppedChar= popQueue();
            while(poppedChar == *sPtr)
            {
                sPtr++;
                if (poppedChar != *sPtr)
                {
                    if(!isEmpty())
                    {
                        poppedChar = popQueue();
                    }
                    else
                    {
                        break;
                    }
                }
            }

            pPtrOffset = 1;
            while(*(pPtr+pPtrOffset) == *(pPtr-1))
            {
                if (*sPtr == *(pPtr+pPtrOffset))
                {
                    ++sPtr;
                    ++pPtrOffset;
                }
                else
                {
                    return false;
                }
            }

            while (checkMatch(sPtr, pPtr-1))
            {
                ++sPtr;
                if (*sPtr == 0)
                {
                    break;
                }
            }

            pPtr = pPtr + pPtrOffset;
            continue;
        }
        else if (*pPtr == '.')
        {
        }
        else
        {
            if (*sPtr != *pPtr)
            {
                if (*(pPtr+1) == '*')
                {
                    ++pPtr;
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        ++sPtr;
        ++pPtr;
    }


    // Finished reading string but not finished reading pattern
    if (*pPtr != 0)
    {
        // Read if all patterns following are useless
        while (*(pPtr+1) == '*')
        {
            pPtr = pPtr + 2;
            if (*pPtr == 0)
            {
                break;
            }
        }

        numOfRemainigPattern = 0;
        while (*pPtr != 0)
        {
            ++numOfRemainigPattern;
            ++pPtr;
        }
        sPtr = sPtr - numOfRemainigPattern;
        while(*pPtr == *sPtr)
        {
            ++pPtr;
            ++sPtr;
        }

        if (*pPtr != 0 || *sPtr != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // char input[] = "aab";
    // char pattern[] = "c*a*b";
    char input[] = "aaa";
    char pattern[] = "ab*a*c*a";
    // char input[] = "ab";
    // char pattern[] = ".*";
    // char input[] = "mississippi";
    // char pattern[] = "mis*is*p*.";
    // char input[] = "aa";
    // char pattern[] = "a";
    // char input[] = "a";
    // char pattern[] = "ab*";
    printf("Input: %s\n", input);
    printf("Pattern: %s\n", pattern);
    printf(isMatch(input, pattern) ? "true" : "false");
}