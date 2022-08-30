/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

#include <stack>

#include<vector>
#include<iostream>
// @lc code=start
class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
    {
        int length = temperatures.size();
        std::vector<int> result(length,0);
        std::stack<int> stack;

        for(int i{0};i<length;++i)
        {
            while(!stack.empty() && temperatures.at(i)>temperatures.at(stack.top()))
            {
                result.at(stack.top())=i-stack.top();
                stack.pop();
            }
                stack.push(i);

        }
        return result;
    }

};
// @lc code=end


int main()
{
    Solution s;
    std::vector v{73,74,75,71,69,72,76,73};
    for(auto i:s.dailyTemperatures(v))
        std::cerr<<i<<'\t';
    return 0;
}