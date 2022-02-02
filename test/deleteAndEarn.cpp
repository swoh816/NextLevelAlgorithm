#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAX_VECTOR_SIZE 20005

class Solution {
    // std::vector<int> addedVector;
    int addedVector[20005];
    int maxNum;
public:
    // Solution():addedVector(20005){}

    int deleteAndEarn(std::vector<int>& nums) {
        for(auto it = nums.begin(); it != nums.end(); it++)
        {
            addedVector[*it] += *it;
            if (maxNum < *it)
            {
                maxNum = *it;
            }
        }

        addedVector[2] += addedVector[0];
        for(int i=3; i<maxNum+1; i++)
        {
            addedVector[i] += addedVector[i-2] > addedVector[i-3] ? addedVector[i-2] : addedVector[i-3];
        }

        return addedVector[maxNum] > addedVector[maxNum-1] ? addedVector[maxNum] : addedVector[maxNum-1];
    }
};

int main()
{
    Solution s;
    std::vector <int> nums = {3, 4, 2};
    std::cout << s.deleteAndEarn(nums) << std::endl;
    return 0;
}