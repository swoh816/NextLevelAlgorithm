#include <stdio.h>

void bubbleSort(int* arr, int arrSize)
{
    int temp;
    int endPoint = 1;
    while(true)
    {
        for(int i=0; i<arrSize-endPoint; i++)
        {
            temp = arr[i] < arr[i+1] ? arr[i] : arr[i+1];
            if (temp == arr[i])
            {
                continue;
            }
            else
            {
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
        endPoint++;
        if(endPoint == arrSize)
        {
            break;
        }
    }
}

int recursiveSolution(int* nums, int subSum, int originalResult, int numIdx)
{
    int result = originalResult;
    for (int i=numIdx-1; i>=0 ; i--)
    {
        if (result+nums[i] <= subSum/2)
        {
            result += nums[i];
            if (result == subSum/2)
            {
                return result;
            }
            if (i > 0)
            {
                result = recursiveSolution(nums, subSum, result, i);
            }
            result -= nums[i];
        }
        else
        {
            continue;
        }
    }
    return originalResult;
}

int subSum;
int maxNum;

bool canPartition(int* nums, int numsSize){
    maxNum = 0;
    subSum = 0;
    for (int i=0; i<numsSize; i++)
    {
        if (maxNum < nums[i])
        {
            maxNum = nums[i];
        }
        subSum += nums[i];
    }
    if (maxNum > subSum/2 || subSum%2 == 1)
    {
        return false;
    }
    printf("subSum: %d\n", subSum);
    
    bubbleSort(nums, numsSize);
    for (int i=numsSize-1; i>=0 ; i--)
    {
        int result = 0;
        if (result+nums[i] <= subSum/2)
        {
            result += nums[i];
            if (i > 0)
            {
                result = recursiveSolution(nums, subSum, result, i);
            }

            // printf("result: %d\n", result);
            // printf("nums[i]: %d\n", nums[i]);
            if (result == subSum/2)
            {
                return true;
            }
        }
        else
        {
            continue;
        }
    }
    return false;
}

int main()
{
    // int nums[] = {1,5,2,11,5};
    // int numSize = 5;
    // bubbleSort(nums, numSize);
    // int nums[] = {14,9,8,4,3,2};
    int nums[200] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,97};
    int numSize = 200;

    printf(canPartition(nums, numSize) ? "true" : "false");
}