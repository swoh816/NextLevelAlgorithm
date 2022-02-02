#include <vector>
#include <string>
#include <iostream>

class Solution {
private:
    int nSubsets;
    int answer;

    int strSize;
    int strsCnt[600][2];

public:
    int findMaxForm(std::vector<std::string>& strs, int m, int n) {
        answer = 0;
        strSize = strs.size();

        for (int i=0; i<strSize; i++)
        {
            strsCnt[i][0] = 0;
            strsCnt[i][1] = 0; // ++nZeros : ++nOnes;
            for(int j=0; j<strs[i].size(); j++)
            {
                strs[i][j] == '0' ? ++strsCnt[i][0] : ++strsCnt[i][1]; // ++nZeros : ++nOnes;
            }
        }

        for (int i=0; i<strSize; i++)
        {
            if(nSubsets + strSize - i < answer)
            {
                break;
            }
            nSubsets = 0;
            recursiveFunction(strs, i, m, n);
        }
        return answer;
    }

    void recursiveFunction(std::vector<std::string>& strs, int startIdx, int m, int n)
    {
        if (m == 0 && n == 0)
        {
            if (nSubsets > answer)
            {
                answer = nSubsets;
            }
        }
        else
        {
            for (int i=startIdx; i<strSize; i++)
            {
                if (m-strsCnt[i][0] >= 0 && n-strsCnt[i][1] >= 0)
                {
                    ++nSubsets;
                    recursiveFunction(strs, i+1, m-strsCnt[i][0], n-strsCnt[i][1]);
                    --nSubsets;
                }
            }
            if (nSubsets > answer)
            {
                answer = nSubsets;
            }
        }
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
    int m = 9;
    int n = 80;

    Solution s;
    std::cout << s.findMaxForm(strs, m, n) << std::endl;
    return 0;
}