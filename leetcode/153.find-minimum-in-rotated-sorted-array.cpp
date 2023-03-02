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
    int findMin(std::vector<int> &nums)
    {
        int start{0};
        int end{static_cast<int>(nums.size()) - 1};
        while (start < end)
        {
            int mid{(start + end) / 2};
            if (nums[mid] < nums[end])
                end = mid;
            else
            {
                start = mid + 1;
            }
        }
        return nums[start];
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