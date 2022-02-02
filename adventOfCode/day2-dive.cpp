#include <string.h>
#include <stdio.h>
#include <iostream>

// int main()
// {
//     int a;
//     char aStr[10] = "1001";
//     // char* aStr = "1001";
//     a = atoi(aStr);
//     printf("%d\n", a);
    
//     char test1[4] = "Hey";
//     char mallocChar[3];
//     strcpy(mallocChar, test1);
//     printf("mallocChar: %s\n", mallocChar);
//     if(strcmp(mallocChar, test1) == 0) // TRUE!!!!!
//     // if(strcmp(test1, test2) == 0)
//     {
//         printf("%s\n", test1);
//     }
// }



#define STRLEN 256

// // PART 1
// int verticalDistance;
// int horizontalDistance;

// // void move(char* direction, int distance)
// void move(char direction[], int distance)
// {
//     if (strcmp(direction, "forward") == 0)
//     {
//         horizontalDistance += distance;
//     }
//     else if (strcmp(direction, "up") == 0)
//     {
//         verticalDistance += distance;
//     }
//     else{
//         verticalDistance -= distance;
//     }
// }

// char direction[8]; // forward, up, down
// char distance[2];

// int main()
// {
//     FILE *pFile = fopen("./input_day2.txt", "r");
//     char string[STRLEN];
//     while (fgets(string, STRLEN, pFile) != NULL)
//     {
//         strncpy(direction, strtok(string, " "), sizeof(string));
//         strncpy(distance, strtok(NULL, " "), sizeof(string));
//         move(direction, atoi(distance));
//     }
//     printf("verticalDistance: %d\n", verticalDistance);
//     printf("horizontalDistance: %d\n", horizontalDistance);
//     printf("Answer %d\n", verticalDistance*horizontalDistance);

//     return 0;
// }



// PART 2
long long verticalDistance;
long long verticalAim;
long long horizontalDistance;

// void move(char* direction, int distance)
void move(char direction[], long long distance)
{
    if (strcmp(direction, "forward") == 0)
    {
        horizontalDistance += distance;
        verticalDistance += distance*verticalAim;
    }
    else if (strcmp(direction, "up") == 0)
    {
        verticalAim += distance;
    }
    else{
        verticalAim -= distance;
    }
}

char direction[8]; // forward, up, down
char distance[2];

int main()
{
    FILE *pFile = fopen("./input_day2.txt", "r");
    char string[STRLEN];
    while (fgets(string, STRLEN, pFile) != NULL)
    {
        strncpy(direction, strtok(string, " "), sizeof(string));
        strncpy(distance, strtok(NULL, " "), sizeof(string));
        move(direction, atoi(distance));
    }
    printf("verticalDistance: %lld\n", verticalDistance);
    printf("horizontalDistance: %lld\n", horizontalDistance);
    printf("Answer %lld\n", verticalDistance*horizontalDistance);

    return 0;
}



    // FILE *pFile = fopen("./input_day2.txt", "r");
    // char string[STRLEN];
    // fgets(string, STRLEN, pFile);
    // char string[100] = "Hello there, how is everything? We haven't seen each other for a while";
    // printf("%s\n", string);
    // char* pch;
    // pch = strtok(string, " ");
    // printf("%s\n", pch);
    // pch = strtok(NULL, " ");
    // printf("%s\n", pch);
    // pch = strtok(NULL, " ");
    // printf("%s\n", pch);

// FILE *pFile;
// char myString[256];
// pFile = fopen("./input.txt", "r");
// while(fgets(myString, 256, pFile) != NULL)
// {
//     printf("%s", myString);
// }
// return 0;

// FILE *pFile = fopen("./input.txt", "r");
// char string[STRLEN];
// fgets(string, STRLEN, pFile);
// printf("%s\n", string);
// printf("%d\n", string);

// freopen("./input.txt", "r", stdin);
// char string[STRLEN];
// scanf("%s\n", &string);
// printf("%s\n", string);
// printf("%d\n", string);