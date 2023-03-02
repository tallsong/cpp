/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

#include <vector>
#include <unordered_map>
// @lc code=start
class Solution
{
public:
    int fourSumCount(std::vector<int> &nums1, std::vector<int> &nums2, std::vector<int> &nums3, std::vector<int> &nums4)
    {
        std::unordered_map<int, int> count;
        int answer{0};
        for (auto n1 : nums1)
        {
            for (auto n2 : nums2)
            {
                ++count[n1 + n2];
            }
        }

        for (auto n3 : nums3)
        {
            for (auto n4 : nums4)
            {
                answer += count[-n3 - n4];
            }
        }
        return answer;
    }
};
// @lc code=end
