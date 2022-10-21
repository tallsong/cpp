/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

// @lc code=start
class Solution
{
public:
    int jump(std::vector<int> &nums)
    {
        int end{0};
        int step{0};
        int max_position { 0 };
        int n{int(nums.size())};
        for (int i{0}; i < n - 1; ++i)
        {
            if (max_position >= i)
            {
                max_position = std::max(max_position, i + nums.at(i));
                if (i == end)
                {

                    end = max_position;
                    ++step;
                }
            }
        }
        return step;
    }
};
// @lc code=end

int main()
{

    Solution s;
    std::vector<int> nums{2, 2, 3, 3, 7, 0, 7};
    std::cerr << s.jump(nums);
    return 0;
}
