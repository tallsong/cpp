/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

#include <vector>

// @lc code=start

class Solution_std
{
public:
    int binarySearch(std::vector<int> &nums, int target, bool lower)
    {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target))
            {
                right = mid - 1;
                ans = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }

    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target)
        {
            return std::vector<int>{leftIdx, rightIdx};
        }
        return std::vector<int>{-1, -1};
    }
};

class Solution
{
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        int n{int(nums.size())};
        if (!n)
            return {-1, -1};
        if (n == 1)
        {
            if (nums.at(0) == target)
                return {0, 0};
            else
                return {-1, -1};
        }
        int left{0};
        int right{n - 1};
        while (left <= right)
        {
            int mid{(left + right) / 2};
            if (nums.at(mid) == target)
            {
                int start{mid};
                int end{mid};
                while (start - 1 >= 0 && nums.at(start - 1) == target)
                {
                    --start;
                }
                while (end + 1 < n && nums.at(end + 1) == target)
                {
                    ++end;
                }
                return {start, end};
            }
            if (nums.at(mid) < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return {-1, -1};
    }
};
// @lc code=end

//  [5,7,7,8,8,10]

int main()
{

    std::vector<int> numns{1, 2, 3};
    Solution s;
    s.searchRange(nums,1);
}