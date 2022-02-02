#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
    std::vector<int> addedVector;
public:
    int deleteAndEarn(std::vector<int>& nums) {
        for(auto it = nums.begin(); it != nums.end(); it++)
        {
            addedVector[*it] += *it;
        }

        addedVector[2] += addedVector[0];
        auto it = addedVector.begin();
        for(it; it != addedVector.end(); it++)
        {
            *it += *(it-2) > *(it-3) ? *(it-2) : *(it-3);
        }

        return *it > *(it-1) ? *it : *(it-1);
    }
};
// int main()
// {
//     std::vector <int> test(100);
//     Solution s;
//     std::vector <int> nums = {2,2,3,3,3,4};
//     s.deleteAndEarn(nums);
//     return 0;
// }