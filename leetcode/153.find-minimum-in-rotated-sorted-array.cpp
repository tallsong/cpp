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
        int low{0};
        int high{ static_cast<int>(nums.size() )  - 1};

        while (low < high)
        {
            int pivot{(low + high) / 2};
            if (nums[pivot] < nums[high])
            {
                high = pivot;
            }
            else
            {   
                //pivot+1 instead of pivot
                low = pivot+1;
            }
        }
        return nums[low];
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