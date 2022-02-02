#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
    int costDp[1000];
    int costDpIdx;
public:
    Solution()
    {
        // costDpIdx = 0;
        // costDp[0] = cost[0];
        // costDp[1] = cost[1];
    }
    int minCostClimbingStairs(std::vector<int>& cost) {
        costDp[0] = cost[0];
        costDp[1] = cost[1];
        costDpIdx = 2;
        for (auto i = cost.begin() + 2; i != cost.end(); ++i) {
            costDp[costDpIdx] = costDp[costDpIdx-1] < costDp[costDpIdx-2] ? costDp[costDpIdx-1] : costDp[costDpIdx-2];
            costDp[costDpIdx] += *i;
            costDpIdx++;
        }        
        return costDp[costDpIdx-1] < costDp[costDpIdx-2] ? costDp[costDpIdx-1] : costDp[costDpIdx-2];
    }
};

int main() {
    Solution s;
    std::vector<int> cost = {10, 15, 20};
    std::cout << s.minCostClimbingStairs(cost) << std::endl;
    return 0;
}