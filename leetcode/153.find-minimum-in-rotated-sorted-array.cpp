/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */
#include <iostream>
#include <vector>
// @lc code=start
class Solution
{
public:
    int findMin(std::vector<int>& nums)
    {
        int start{0};
        int end{int(nums.size() - 1)};
        while (start + 1 < end)
        {
            int mid{(start + end) / 2};
            if (nums[mid] > nums[end])
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        return std::min(nums[start], nums[end]);
    }
};
// @lc code=end

int main()
{
    Solution s;
    std::vector<int> v{11, 13, 15, 17};
    std::cerr << s.findMin(v);
    return 0;
}