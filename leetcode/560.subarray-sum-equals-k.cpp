/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

#include <vector>
#include <unordered_map>
// @lc code=start
class Solution
{
public:
    int subarraySum(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> map;
        map[0] = 1;

        int count{0};
        int pre{0};
        for (auto num : nums)
        {
            pre += num;
            count += map[pre - k];
            map[pre]++;
        }
        return count;
    }
};
// @lc code=end

int main()
{
    std::vector<int> v{1, 2, 1, 2, 1};
    Solution s;
    s.subarraySum(v, 3);

    return 0;
}
