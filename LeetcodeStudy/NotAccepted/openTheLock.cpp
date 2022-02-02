#include <stdio.h>

int openLock(char ** deadends, int deadendsSize, char * target){
    int numTurns = 0;
    char* deadend;
    for (int deadendsIdx = 0; deadendsIdx < deadendsSize; deadendsIdx++)
    {
        deadend = *(deadends + deadendsIdx);
    }

    return numTurns;
};


// int main()
// {
//     char** deadends = {"0201", "0101", "0102", "1212", "2002"};
//     char** deadendsPtr = deadends;
//     int deadendsSize = 0;
//     while (**deadendsPtr != '\0')
//     {
//         deadendsSize++;
//     }
//     printf("Size %d", deadendsSize);
//     // char* target = "0202";
// 
//     // int answer = openLock();
//     return 0;
// }