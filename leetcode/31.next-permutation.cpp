/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

#include <vector>
#include <iostream>
// @lc code=start
class Solution
{
public:
    void nextPermutation(std::vector<int> &nums)
    {
        int i{int(nums.size()) - 2};
        while (i >= 0 && nums.at(i) >= nums.at(i + 1))
        {
            --i;
        }
        if (i >= 0)
        {
            int j{int(nums.size()) - 1};
            while (j>=0 && nums.at(j) <= nums.at(i))
            {
                --j;
            }
            std::swap(nums.at(j), nums.at(i));
        }
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end

int main()
{
    std::vector<int> nums{4, 5, 2, 6, 3, 1};
    // std::vector<int> nums{1,3,2};
    Solution s;
    s.nextPermutation(nums);
    for (auto i : nums)
    {
        std::cerr << i << '\t';
    }
}
