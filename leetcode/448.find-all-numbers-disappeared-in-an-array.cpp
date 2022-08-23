/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

#include <vector>
#include <iostream>
#include <unordered_set>

class Solution
{
public:
    std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
    {

        std::unordered_set<int> s;
        for (auto num : nums)
            s.insert(num);
        std::vector<int> v;

        for(int num{1};num<=nums.size();++num)
        {

            if (!s.count(num))
            {
                v.insert(v.begin(), num);
            }
        }
        return v;
    }
};

int main()
{
    Solution s;
    std::vector<int> v{4,3,2,7,8,2,3,1};
    for(auto num:s.findDisappearedNumbers(v))
        std::cerr<<num;
    return 0;
}