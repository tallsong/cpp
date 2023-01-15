/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

#include <vector>

// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
    {
        int n = gas.size();
        int i{0};
        while (i < n)
        {
            int cur{0};
            int j{0};
            while (j < n)
            {
                int index = (j + i) % n;
                cur += (gas[index] - cost[index]);
                if (cur < 0)
                {
                    break;
                }
                ++j;
            }
            if (j == n)
                return i;

            i = i + j + 1;
        }
        return -1;
    }
};
// @lc code=end

int main()
{

    std::vector<int> gas{1, 2, 3, 4, 5};
    std::vector<int> cost{3, 4, 5, 1, 2};
    Solution s;
    s.canCompleteCircuit(gas, cost);
    return 0;
}