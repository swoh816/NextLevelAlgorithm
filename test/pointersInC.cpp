#include <stdio.h>

// int printArrayElement(int* A)
// {
    // for(int i, )
// }

int main()
{
    int A[5] = {10, 3, 28, 9, 5};
    printf("A: %p\n", A);
    printf("Address of A: %p\n", &A);
    printf("A[0]: %p\n", A[0]);
    printf("Address of A[0]: %d\n", A[0]);

    int B[2][3] = {{2, 3, 1}, {29, 10, 99}};
    printf("B: %d\n", B);
    printf("Address of B: %d\n", &B);
    printf("B[0]: %d\n", B[0]);
    printf("Address of B[0]: %d\n", &B[0]);
    printf("B[0][0]: %d\n", B[0][0]);
    printf("**B: %d\n", **B);
    printf("*B: %d\n", *B[1]);
    
    // int C[2][2][3] = {{{288, 388, 188}, {2988, 1088, 9988}}, {{2, 3, 1}, {29, 10, 99}}};
    // printf("C: %d\n", C);
    // printf("Address of C: %d\n", &C);
    // printf("C[0]: %d\n", C[0]);
    // printf("Address of C[0]: %d\n", &C[0]);

    return 0;
}