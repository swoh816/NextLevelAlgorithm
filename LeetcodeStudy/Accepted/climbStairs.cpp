#include <iostream>

class Solution {
    long long combinationTable[100][50];
    long long answer;
public:
    Solution()
    {
        for(int i=0; i<100; i++)
        {
            combinationTable[i][1] = i;
            combinationTable[i][0] = 1;
            answer = 0;
        }
    }

    long long combination(int n, int r) // nCr
    {
        if (combinationTable[n][r] != 0)
        {
            return combinationTable[n][r];
        }
        else
        {
            combinationTable[n][r] = combination(n-1, r-1)*n/r;
            return combinationTable[n][r];
        }
    }
    
    int climbStairs(int n) { // Mathematical solution
        int quotient = n/2;
        if (n%2 == 1)
        {
            // quotient+1 C 1
            // quotient-1+2+1 C 3
            // quotient-2+4+1 C 5
            // quotient-3+6+1 C 7
            // ...
            // quotient-quotient+2*quotient+1 C 2*quotient+1
            for(int i=0; i<=quotient; i++) 
            {
                answer += combination(quotient-i+2*i+1, 2*i+1);
            }
            return answer;
        }
        else
        {
            // quotient+0 C 0
            // quotient-1+2 C 2
            // quotient-2+4 C 4
            // quotient-3+6 C 6
            // ...
            // quotient-quotient+2*quotient C 2*quotient
            for(int i=0; i<=quotient; i++) 
            {
                answer += combination(quotient-i+2*i, 2*i);
            }
            return answer;
        }
    }
};

int main()
{
    Solution s;
    std::cout << s.climbStairs(2) << std::endl;
    return 0;
}

// #include <iostream>
// int main()
// {
//     // printf("%d\n", 0);
//     std::cout << 0 << std::endl;
//     return 0;
// }