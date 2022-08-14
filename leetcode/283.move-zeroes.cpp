/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
#include<algorithm>
#include <vector>
class Solution
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        size_t slow{0};
        for (auto i{0}; i < nums.size(); ++i)
        {
            if (nums.at(i) != 0)
            {
                std::swap(nums.at(i), nums.at(slow++));
            }
        }
    }
};
// @lc code=end

int main()
{
    Solution solution;
    std::vector<int> nums{0, 1, 0, 3, 12};
    solution.moveZeroes(nums);
    return 0;
}
