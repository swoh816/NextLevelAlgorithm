#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() <= 2)
        {
            return *std::max_element(nums.begin(), nums.end());
        }
        else
        {
            nums[2] = nums[0] + nums[2];
            auto it=nums.begin()+3;
            for (it; it != nums.end(); it++)
            {
                *it += *(it-2) > *(it-3) ? *(it-2) : *(it-3);
            }
            return *(it-1) > *(it-2) ? *(it-1) : *(it-2);
        }
    }
};

int main()
{
    // std::vector<int> nums = {2,7,9,3,1};
    // std::vector<int> nums = {1, 2, 3, 1};
    std::vector<int> nums = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Solution s;
    std::cout << s.rob(nums) << std::endl;
    return 0;
}