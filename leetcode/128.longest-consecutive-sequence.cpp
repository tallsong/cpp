/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

#include <unordered_set>
#include <iostream>
#include <vector>
// @lc code=start

class Solution
{
public:
    int longestConsecutive(std::vector<int> &nums)
    {
        std::unordered_set<int> u1;
        std::unordered_set<int> u2;
        for (const int num : nums)
        {
            u1.insert(num);
        }
        int result{0};
        for (int num : nums)
        {
            if (u2.count(num))
                continue;
            else
            {
                int temp{0};
                int n{num};
                while (u1.count(n))
                {
                    ++temp;
                    u2.insert(n);
                    ++n;
                }
                result = std::max(result, temp);
            }
        }
        return result;
    }
};
// @lc code=end

int main()
{
    std::vector<int> v{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    // std::vector<int> v{100, 4, 200, 1, 3, 2};
    Solution s;
    std::cerr << s.longestConsecutive(v);
    return 0;
}