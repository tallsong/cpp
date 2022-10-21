/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

#include <iostream>
#include <unordered_set>
#include <vector>
// @lc code=start

class Solution
{
public:
    void helper(std::vector<std::vector<int>> &results, std::vector<int> &result,std::vector<int> &nums)
    {
        if(result.size()==nums.size())
        {

            results.push_back(result);
            return;
        }
        for(auto num:nums)
        {
            if(std::find(result.begin(), result.end(), num) == result.end())
            {
                result.push_back(num);
                helper(results,result,nums);
                result.pop_back();
            }
        }
    }
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> results;
        std::vector<int> result;
        helper(results,result,nums);
        return results;
    }
};
// @lc code=end


int main()
{
    std::vector<int> nums{0,1};
    Solution s;
    s.permute(nums);
    return 0;
}
