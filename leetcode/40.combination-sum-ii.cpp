/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 1 1 2 5 6 10
class Solution
{

    vector<vector<int>> result;

    vector<int> current;

    int current_sum{0};

    void helper(int start, int target, vector<int>& candidates)
    {

        if (current_sum == target)
        {
            result.push_back(current);
        }
        if (current_sum > target)
            return;

        for (int index{start}; index < candidates.size(); ++index)
        {
            // 排序以后， 连续相同的数字仅取第一个
            if (index > start && candidates[index] == candidates[index - 1])//还可以使用一个hash记忆这个数字在之前是否出现过
            {
                continue;
            }
            current.push_back(candidates[index]);
            current_sum += candidates[index];

            helper(index + 1, target, candidates);
            current_sum -= candidates[index];
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        ranges::sort(candidates);
        helper(0, target, candidates);
        return result;
    }
};

// @lc code=end
