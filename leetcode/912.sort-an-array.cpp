/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start

#include <iostream>
#include <vector>

// practice quick sort
class Solution_quick_sork
{
    void quick_sort(std::vector<int>& nums, int start, int end)
    {
        if (start >= end)
            return;
        int left{start};
        int right{end};
        int pivot{nums[(start + end) / 2]};
        // <= not <
        /**
         * 0. avoid left and right share same party that case reduntant timer
         * 1. void infinite recursive , such as [1,2 ]
         */
        while (left <= right)
        {
            /**
             * nums[start] < pivot  not <=  since
             * 0. we want to the numvber equal to pivot distribute in two parts equaly
             * 1.  void infinite recursive , such as [1,1 ]
             */
            while (left <= right && nums[left] < pivot)
                ++left;
            while (left <= right && nums[right] > pivot)
                --right;
            if (left <= right)
                std::swap(nums[left++], nums[right--]);
        }
        quick_sort(nums, start, right);
        quick_sort(nums, left, end);
    }

public:
    std::vector<int> sortArray(std::vector<int>& nums)
    {
        quick_sort(nums, 0, int(nums.size()) - 1);
        return nums;
    }
};

class Solution_marge_sork
{
    void merge(std::vector<int>& nums, int start, int end, int mid, std::vector<int>& temporary)
    {
        for (int i{start}; i <= end; ++i)
        {
            temporary[i] = nums[i];
        }
        int left1{start};
        int left2{mid + 1};
        int i{start};
        while (left1 <= mid && left2 <= end)
        {
            if (temporary[left1] < temporary[left2])
            {
                nums[i++] = temporary[left1++];
            }
            else
            {
                nums[i++] = temporary[left2++];
            }
        }
        while (left1 <= mid)
        {
            nums[i++] = temporary[left1++];
        }
        while (left2 <= end)
        {
            nums[i++] = temporary[left2++];
        }
    }

    void merge_sort(std::vector<int>& nums, int start, int end, std::vector<int>& temporary)
    {
        if (start >= end)
            return;
        int mid{(start + end) / 2};
        merge_sort(nums, start, mid, temporary);
        merge_sort(nums, mid + 1, end, temporary);
        merge(nums, start, end, mid, temporary);
    }

public:
    std::vector<int> sortArray(std::vector<int>& nums)
    {
        std::vector<int> temporary(nums.size());
        merge_sort(nums, 0, nums.size() - 1, temporary);
        return nums;
    }
};
// @lc code=end
int main()
{
    Solution_marge_sork solution_marge_sork;
    std::vector<int> nums{1, 2, 3, 7, 8, 6, 4, 5, 0};

    solution_marge_sork.sortArray(nums);
    for (auto num : nums)
    {
        std::cerr << num << '\t';
    }
    std::cerr << "\n  quick sork  \n";
    Solution_quick_sork solution_quick_sork;
    // std::vector<int> nums2{1, 2, 3, 7, 8, 6, 4, 5, 0};
    std::vector<int> nums2{1, 1};
    solution_quick_sork.sortArray(nums2);
    for (auto num : nums2)
    {
        std::cerr << num << '\t';
    }
    return 0;
}
