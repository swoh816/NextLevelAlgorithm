#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Solution {
private:
    int zeroKnapsack[601][101];
    int oneKnapsack[601][101];

    int zeroCnt[101];
    int oneCnt[101];

public:
    int findMaxForm(std::vector<std::string>& strs, int m, int n) {
        int numberOfElements = strs.size();
        for (int i=0; i<numberOfElements; i++)
        {
            for (auto e : strs[i])
            {
                e == '0' ? ++zeroCnt[i] : ++oneCnt[i];
            }
        }
        
        // Maximize zeros while checking if the number of ones does not exceed m
        for (int r = 1; r<numberOfElements+1; r++)
        {
            for (int i=1; i<zeroCnt[r-1]+1; i++)
            {
                zeroKnapsack[r][i] = zeroKnapsack[r-1][i];
            }
            for (int wm = zeroCnt[r-1]+1; wm < m+1; wm++)
            {
                if ()
                zeroKnapsack[r][i] = zeroKnapsack[r-1][i];
            }


        }

        // Maximize ones while checking if the number of zeros does not exceed n
    }
};

int main()
{
    // std::vector<std::string> strs = {"10","0001","111001","1","0"};
    // int m = 5;
    // int n = 3;

    // std::vector<std::string> strs = {"10","0","1"};
    // int m = 1;
    // int n = 1;

    std::vector<std::string> strs = {"0","11","1000","01","0","101","1","1","1","0","0","0","0","1","0",
    "0110101","0","11","01","00","01111","0011","1","1000","0","11101","1","0","10","0111"};
    // int m = 9;
    // int n = 80;

    return 0;
}