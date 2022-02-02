#include <stdio.h>

char indexArr[9] = "01234567";
int tickArr[9];
int indexStack[9];

void permutation(int n)
{
    int indexIdx = 0;
    while (indexArr[indexIdx] != 0)
    {
        if (tickArr[indexIdx] != -1)
        {
            indexStack[9-n] = (int)(indexArr[indexIdx])-48;
            tickArr[indexIdx] = -1;
            if (n != 1)
            {
                permutation(n-1);
            }
            else
            {
                printf("Permutation: ");
                for(int i=0; i<9; i++)
                {
                    printf("%d", indexStack[i]);
                }
                printf("\n");
            }
        }
        indexIdx++;
    }
}

int main()
{
    permutation(6);
    return 0;
}