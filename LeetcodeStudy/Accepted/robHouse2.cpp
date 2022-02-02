#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
private:
    int answer1;
    int answer2;
    std::vector <int> numsCopy;
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() <= 3)
        {
            return *std::max_element(nums.begin(), nums.end());
        }
        else
        {
            numsCopy = nums;
            numsCopy[2] = numsCopy[0] + numsCopy[2];
            auto it=numsCopy.begin()+3;
            for (it; it != numsCopy.end()-1; it++)
            {
                *it += *(it-2) > *(it-3) ? *(it-2) : *(it-3);
            }
            answer1 = *(it-1) > *(it-2) ? *(it-1) : *(it-2);

            nums[3] = nums[1] + nums[3];
            it=nums.begin()+4;
            for (it; it != nums.end(); it++)
            {
                *it += *(it-2) > *(it-3) ? *(it-2) : *(it-3);
            }
            answer2 = *(it-1) > *(it-2) ? *(it-1) : *(it-2);
            return answer1 > answer2 ? answer1 : answer2;
        }
    }
};

// class Solution {
// private:
//     int addNum;
//     // int includeZeroth[1000];
//     // std::vector <int> includeZeroth;
//     int answer;

// public:
//     int rob(std::vector<int>& nums) {
//         int includeZeroth[1000];
//         if (nums.size() <= 3)
//         {
//             return *std::max_element(nums.begin(), nums.end());
//         }
//         else
//         {
//             nums[2] = nums[0] + nums[2];
//             includeZeroth[0] = 1;
//             includeZeroth[2] = includeZeroth[0];
//             int i;
//             for (i = 3; i < nums.size()-1; i++)
//             {
//                 if(nums[i-2] > nums[i-3])
//                 {
//                     nums[i] += nums[i-2];
//                     includeZeroth[i] = includeZeroth[i-2];
//                 }
//                 else if(nums[i-2] == nums[i-3])
//                 {
//                     nums[i] += nums[i-2];
//                     includeZeroth[i] = includeZeroth[i-2]*includeZeroth[i-3];
//                 }
//                 else
//                 {
//                     nums[i] += nums[i-3];
//                     includeZeroth[i] = includeZeroth[i-3];
//                 }
//             }

//             // if (*(it-3) includes 0)
//             if (includeZeroth[i-3] == 1) // Need to check if i-1 
//             {
//                 nums[i-3] = nums[i-3] > nums[i-3] + nums[i] - nums[0] ?
//                             nums[i-3] : nums[i-3] + nums[i] - nums[0];
//             }
//             else
//             {
//                 nums[i-3] = nums[i-3] + nums[i];
//             }
//             if (includeZeroth[i-2] == 1) // Need to check if i-1 
//             {
//                 nums[i-2] = nums[i-2] > nums[i-2] + nums[i] - nums[0] ?
//                             nums[i-2] : nums[i-2] + nums[i] - nums[0];
//             }
//             else
//             {
//                 nums[i-2] = nums[i-2] + nums[i];
//             }
//             answer = nums[i-3] > nums[i-2] ? nums[i-3] : nums[i-2];
//             return answer > nums[i-1] ? answer : nums[i-1];
//         }
//     }
// };

int main()
{
    // std::vector<int> nums = {2,7,9,3,1};
    // std::vector<int> nums = {1, 2, 3, 1};
    // std::vector<int> nums = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::vector<int> nums = {2,1,2,6,1,8,10,10};
    Solution s;
    std::cout << s.rob(nums) << std::endl;
    return 0;
}