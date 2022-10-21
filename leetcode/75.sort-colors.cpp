/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

#include <vector>

// @lc code=start
class Solution
{
public:
    void sortColors(std::vector<int> &nums)
    {
        int start{0};
        int end{int(nums.size()) - 1};
        int temp{start};
        while (temp <= end)
        {
            while (temp < end && nums.at(temp) == 2)
            {
                std::swap(nums.at(end--), nums.at(temp));
            }
            if (nums.at(temp) == 0)
            {
                std::swap(nums.at(start++), nums.at(temp));
            }

            ++temp;
        }
    }
};
// @lc code=end

int main()
{
    Solution s;
    // std::vector<int> v{2, 0, 2, 1, 1, 0};
    std::vector<int> v{2};
    s.sortColors(v);
    return 0;
}
