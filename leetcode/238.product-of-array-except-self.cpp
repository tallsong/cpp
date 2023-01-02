/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */
#include <vector>
#include <iostream>

// @lc code=start
class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        auto length{int(nums.size())};
        std::vector<int> left(length);
        std::vector<int> right(length);
        std::vector<int> answer(length);

        left[0] = 1;
        left[1] = nums[0];
        right[length - 1] = 1;
        right[length - 2] = nums[length - 1];
        for (int i{2}; i < length; ++i)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }
        for (int i{length - 3}; i >= 0; --i)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }
        for (int i{0}; i < length; ++i)
        {
            answer[i] = left[i] * right[i];
        }
        return answer;
    }
};
// @lc code=end

int main()
{
    std::vector<int> nums{1,2,3,4,};
    Solution s;

    for(auto num:s.productExceptSelf(nums))
    {
        std::cerr<<num<<'\t';
    }
    return 0;
}