/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */
#include <unordered_map>
#include <cmath>
#include <vector>
// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, std::vector<int>> hashtable;

        for (int i{0}; i < nums.size(); ++i)
        {
            if (hashtable.count(nums[i]))
            {
                for (auto index : hashtable[nums[i]])
                {
                    if (i - index <= k)
                        return true;
                }
            }
            hashtable[nums[i]].push_back(i);
        }

        return false;
    }
};
// @lc code=end

int main()
{
    Solution s;

    return 0;
}