/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

#include<vector>
#include<unordered_set>
// @lc code=start
class Solution
{
public:
    int findDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> set;
        for(auto num:nums)
        {
            if(set.count(num))
                return num;
            set.insert(num);
        }
        return 0;        
    }
};
// @lc code=end
