/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
#include<vector>
#include<iostream>
// @lc code=start
class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int n{int(nums.size())};
        if (!n)
            return -1;
        int left{0};
        int right{n - 1};
        while (left <= right)
        {
            int mid{(left + right) / 2};
            if (nums.at(mid) == target)
                return mid;
            if (nums.at(left) <= nums.at(mid))
            {
                if (nums.at(left) <= target && target < nums.at(mid))
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if (nums.at(mid) < target && target <= nums.at(right))
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }
};
// @lc code=end



int  main()
{
    Solution s;
    std::vector<int> nums{3,1};
    std::cerr<<s.search(nums,1);
    return 0;
}
