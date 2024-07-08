/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
#include <iostream>
#include <vector>
// @lc code=start
class Solution2
{

private:
    int getMinimunInindex(std::vector<int>& nums)
    {
        int start{0};
        int end{nums.size() - 1};
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
        if (nums[start] < nums[end])
            return start;
        else
            return end;
    }

public:
    int search(std::vector<int>& nums, int target)
    {
        auto index = getMinimunInindex(nums);
        int start{0};
        int end{nums.size() - 1};
        if (nums[end] >= target && nums[index] <= target)
            start = index;
        else if (index == start)
        {
            end = index;
        }
        else
        {
            end = index - 1;
        }
        while (start + 1 < end)
        {
            int mid{(start + end) / 2};
            if (nums[mid] > target)
            {
                end = mid;
            }
            else
                start = mid;
        }
        if (nums[start] == target)
            return start;
        if (nums[end] == target)
            return end;
        return -1;
    }
};

class Solution
{

public:
    int search(std::vector<int>& nums, int target)
    {

        int start{0};
        int end{int(nums.size()) - 1};
        while (start + 1 < end)
        {
            int mid{(start + end) / 2};
            // mid in the left part
            if (nums[mid] > nums[end])
            {
                if (target >= nums[start] && target <= nums[mid])
                {
                    end = mid;
                }
                else
                {
                    // nums become a smaller rotated sorted array
                    start = mid;
                }
            }
            else
            {
                // array may not be a  rotated array this case, so this conditon must cover this case
                if (target >= nums[mid] && target <= nums[end])
                {
                    start = mid;
                }
                else
                {
                    end = mid;
                }
            }
        }
        if (nums[start] == target)
            return start;
        if (nums[end] == target)
            return end;
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
    std::cerr << s.search(nums, 1) << std::endl;
    std::cerr << s.search(nums2, 0) << std::endl;
    std::cerr << s.search(nums3, 5) << std::endl;
    std::cerr << s.search(nums3, 3) << std::endl;
    return 0;
}
