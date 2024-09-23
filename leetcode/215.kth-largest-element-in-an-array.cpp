/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
#include <cstdlib>
#include <iostream>
#include <vector>
// @lc code=start
class Solution
{
public:
    int findKthLargest(std::vector<int>& nums, int k)
    {
        return quick_select(nums, k - 1, 0, nums.size() - 1);
    }

private:
    int quick_select(std::vector<int>& nums, int k, int start, int end)
    {
        if (start == k && k == end)
        {
            return nums.at(k);
        }
        auto left{start};
        auto right{end};
        int pivot{nums[(left + right) / 2]};
        while (left <= right)
        {
            while (left <= right && nums[left] > pivot)
            {
                ++left;
            }
            while (left <= right && nums[right] < pivot)
            {
                --right;
            }
            if (left <= right)
            {
                std::swap(nums[left++], nums[right--]);
            }
        }
        if (k <= right)
            return quick_select(nums, k, start, right);
        if (k >= left)
            return quick_select(nums, k, left, end);
        // 注意k在right后和left前的情况
        return nums[k];
    }
};

// @lc code=end

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(T215, t1)
{
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    Solution s;
    // Expect equality.
    EXPECT_EQ(s.findKthLargest(nums, 1), 7);
    EXPECT_EQ(s.findKthLargest(nums, 2), 6);
}

// int main()
// {
//     std::vector<int> nums{1, 2, 3, 4, 5, 6, 7};
//     Solution s;
//     // std::cerr<<s.findKthLargest(nums, 1)<<'\n';
//     std::cerr << s.findKthLargest(nums, 2) << '\n';
//     std::cerr << s.findKthLargest(nums, 3) << '\n';
//     std::cerr << s.findKthLargest(nums, 4) << '\n';
//     std::cerr << s.findKthLargest(nums, 5) << '\n';
//     std::cerr << s.findKthLargest(nums, 6) << '\n';
//     std::cerr << s.findKthLargest(nums, 7) << '\n';

//     return 0;
// }