/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */
#include <vector>
#include <algorithm>
#include <iostream>
// @lc code=start
class Solution
{
public:
    std::vector<int> sortArrayByParity(std::vector<int> &nums)
    {
        int start{0};
        int end{int(nums.size()) - 1};
        while (start < end)
        {
            while (start<nums.size()  && nums.at(start) % 2 == 0)
                ++start;
            while (end>=0 && nums.at(end) % 2 != 0)
                --end;
            if (start >= end || start>=nums.size() || end<0)
            {

                break;
            }
            std::swap(nums.at(start), nums.at(end));
        }
        return nums;
    }
};
// @lc code=end

int main()
{
    Solution s;
    std::vector v{2,4,3,1};
    for (auto i : s.sortArrayByParity(v))
    {
        std::cerr << i << '\t';
    }
    std::vector v1{1,3};
    for (auto i : s.sortArrayByParity(v1))
    {
        std::cerr << i << '\t';
    }
    return 0;
}