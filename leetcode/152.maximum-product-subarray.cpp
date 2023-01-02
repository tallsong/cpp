/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */
#include <climits>
#include <vector>
#include <algorithm>
#include <iostream>
// @lc code=start
class Solution
{
public:
    int maxProduct(std::vector<int> &nums)
    {
        int f_max{1};
        int f_min{1};
        int ans{INT_MIN};
        for (const int num : nums)
        {
            int fx = f_max;
            int fn = f_min;
            f_max = std::max(fx * num, std::max(fn * num, num));
            f_min = std::min(fn * num, std::min(fx * num, num));
            ans = std::max(ans, f_max);
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    // std::vector<int> v{2,3,-2,4};
    std::vector<int> v{-2, 0, -1};
    // v=std::vector{-2,0,-1};

    Solution s;
    std::cerr << s.maxProduct(v);
}