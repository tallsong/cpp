/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start

#include <iostream>
#include <vector>
class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        auto start{0};
        auto end{nums.size() - 1};
        while (start + 1 < end)
        {
            auto mid{start + (end - start) / 2};
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                end = mid;
            else
                start = mid;
        }
        // the order of start and end depends on the question
        // for case [5],5
        
        if (nums[start] == target)
            return start;
        if (nums[end] == target)
            return end;

        return -1;
    }
};
// @lc code=end
