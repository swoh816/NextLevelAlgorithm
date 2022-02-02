#include <stdio.h>

int explicitStack[21];
int top;
int gnNumsSize;
int sum;

// Push
void pushStack(int* nums)
{
    while (top != gnNumsSize+1)
    {
        explicitStack[top] = nums[top-1];
        top++;
    }
}

// Pop
void popStack()
{
    // If popped element is positive integer then change to negative
    if (explicitStack[top] > 0)
    {
        explicitStack[top] *= -1;
    }
    // If popped element is negative integer then move one level higher
    else
    {
        while (explicitStack[top] <= 0 & top > 0) // pop element
        {
            top--;
        }
        explicitStack[top] *= -1;
    }
    top++;
}

int findTargetSumWays(int* nums, int numsSize, int target){
    gnNumsSize = numsSize;
    int numOfWays = 0;
    top = 1;
    
    do {
        sum = 0;
        pushStack(nums);
        for(int i=1; i<=numsSize; i++)
        {
            sum += explicitStack[i];
        }
        if (sum == target)
        {
            numOfWays++;
        }
        top--;
        popStack();
    } while (top > 1);

    for(int i=0; i<numsSize; i++)
    {
        if (nums[i] == 0)
        {
            numOfWays *= 2;
        }
    }

    return numOfWays;
}

int main()
{
    // int nums[] = {1, 1, 1, 1, 1};
    // int numsSize = 5;
    // int target = 3;
    // int nums[] = {30,1,5,32,16,17,30,29,48,14,29,4,31,12,40,13,13,20,41,38};
    // int numsSize = 20;
    // int target = 9;
    int nums[] = {35,37,9,29,36,0,44,32,44,13,2,37,14,21,41,36,9,23,41,17};
    int numsSize = 20;
    int target = 42;
    
    
    int answer = findTargetSumWays(nums, numsSize, target);
    printf("The answer: %d\n", answer);
    return 0;
}