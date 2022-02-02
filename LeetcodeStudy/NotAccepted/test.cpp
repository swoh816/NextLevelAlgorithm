#include <stdio.h>
#include <malloc.h>
int main()
{
    // int aNum = int('a');
    // printf("%d", aNum);
    // char a[] = "Abc";
    // char* aPtr = a;
    // while (*aPtr != '\0')
    // {
    //     printf("%c", *aPtr);
    //     aPtr++;
    // }

    // int a, b = 2, 1;
    // printf("%d %d", a, b);
    // int a[2][2] = {{1,2}, {3,4}};
    int matSize = 2;
    int* matColSize;
    matColSize = &matSize;
    // int** result = (int**)malloc(sizeof(int)*matSize*(*matColSize));
    int result[2][2] = {0};
    // int a[2][2] = {1, 2, 3, 4};
    printf("%d\n", *(*(result+1)+1));
    printf("%d\n", result[1][1]);
    // for (int i=0; i<4; i+=2)
    // {
    //     printf("%d", i);
    // }
    return 0;
}