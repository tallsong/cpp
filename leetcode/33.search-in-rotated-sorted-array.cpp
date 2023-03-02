/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
#include <vector>
#include <iostream>
// @lc code=start
class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int n = int(nums.size());
        if (!n)
            return -1;
        if (n == 1)
            return nums[0] == target ? 0 : -1;
        int start{0};
        int end{n - 1};
        while (start <= end)
        {
            int mid{(start + end) / 2};
            if (nums[mid] == target)
                return mid;
            if (nums[0] <= nums[mid])
            {
                if (nums[0] <= target && target < nums[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                if (target > nums[mid] && target <= nums[n - 1])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

int main()
{
    Solution s;
    std::vector<int> nums{3, 1};
    std::vector<int> nums2{4, 5, 6, 7, 0, 1, 2};
    std::vector<int> nums3{5, 1, 3};
    std::cerr << s.search(nums3, 5);
    std::cerr << s.search(nums2, 0);
    std::cerr << s.search(nums, 1);
    return 0;
}
