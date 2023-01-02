/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

#include <vector>
#include <iostream>
#include <climits>
// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int length = nums.size();
        if (length == 1)
            return nums[0];
        if (length == 2)
            return std::max(nums[0], nums[1]);
        int ppre = nums[0];
        int pre = 0;

        pre = std::max(nums[0], nums[1]);

        for (int i{2}; i < length; ++i)
        {
            int temp = pre;
            pre = std::max(ppre + nums[i], pre);
            ppre = temp;
        }
        return pre;
    }
};

int main()
{
    return
}