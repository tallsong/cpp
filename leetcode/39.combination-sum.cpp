/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

#include <vector>

// @lc code=start
class Solution
{
public:
    void helper(std::vector<std::vector<int>> &result, std::vector<int> &combine, int idx, int target, std::vector<int> &candidates)
    {
        if (int(candidates.size()) == idx)
            return;
        if (target == 0)
        {
            result.push_back(combine);
            return;
        }
        helper(result, combine, idx + 1, target, candidates);
        if (target - candidates.at(idx) >= 0)
        {
            combine.push_back(candidates.at(idx));
            helper(result, combine, idx, target - candidates.at(idx), candidates);
            combine.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
    {
        std::vector<int> combine;
        std::vector<std::vector<int>> result;
        helper(result, combine, 0, target, candidates);
        return result;
    }
};

// @lc code=end

int main()
{
    return 0;
}
