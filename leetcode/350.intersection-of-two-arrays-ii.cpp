/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */
#include <vector>
#include <unordered_map>
// @lc code=start
class Solution
{
public:
    std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::unordered_map<int, int> count;
        for (auto num : nums1)
        {
            ++count[num];
        }
        std::vector<int> intersection;
        for (auto num : nums2)
        {
            if (count[num] > 0)
            {
                intersection.push_back(num);
                --count[num];
            }
        }
        return intersection;
    }
};
// @lc code=end
