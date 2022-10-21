/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

#include <vector>
#include <iostream>
// @lc code=start

class Solution_std {
public:
    bool canJump(std::vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= rightmost) {
                rightmost = std::max(rightmost, i + nums[i]);
                if (rightmost >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};


class Solution
{
public:
    bool canJump(std::vector<int> &nums)
    {
        int i{int(nums.size()) - 1};

        while (i >= 0)
        {
            if (!nums.at(i) && i!=nums.size()-1)
            {
                int gap{1};
                while (i >= 0)
                {
                    --i;
                    if (i< 0)
                        return false;
                    if (nums.at(i) > gap)
                        break;
                    ++gap;
                }
            }
            --i;
        }
        return true;
    }
};
// @lc code=end

int main()
{
    Solution s;
    std::vector v0{2, 0, 6, 9, 8, 4, 5, 0, 8, 9, 1, 2, 9, 6, 8, 8, 0, 6, 3, 1, 2, 2, 1, 2, 6, 5, 3, 1, 2, 2, 6, 4, 2, 4, 3, 0, 0, 0, 3, 8, 2, 4, 0, 1, 2, 0, 1, 4, 6, 5, 8, 0, 7, 9, 3, 4, 6, 6, 5, 8, 9, 3, 4, 3, 7, 0, 4, 9, 0, 9, 8, 4, 3, 0, 7, 7, 1, 9, 1, 9, 4, 9, 0, 1, 9, 5, 7, 7, 1, 5, 8, 2, 8, 2, 6, 8, 2, 2, 7, 5, 1, 7, 9, 6};
    std::vector v1{0};
    std::vector v2{2, 3, 1, 1, 4};
    std::vector v3{3, 2, 1, 0, 4};
    std::vector<std::vector<int>> vv{v0, v1, v2, v3};
    for (int i{0}; i < vv.size(); ++i)
    {

        if (s.canJump(vv.at(i)))
            std::cerr << "jump!\n";
        else
            std::cerr << "not jump!\n";
    }
}