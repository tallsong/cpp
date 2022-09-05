/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

#include <stack>

#include <vector>
#include <iostream>
// @lc code=start
class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
    {
        std::vector<int> result(temperatures.size());
        std::stack<int> stk;
        for (size_t i{0}; i < temperatures.size(); ++i)
        {

            while (!stk.empty() && temperatures.at(stk.top()) < temperatures.at(i))
            {
                result.at(stk.top()) = i - stk.top();
                stk.pop();
            }
            stk.emplace(i);
        }
        return result;
    }
};
// @lc code=end

int main()
{
    Solution s;
    std::vector v{73, 74, 75, 71, 69, 72, 76, 73};
    for (auto i : s.dailyTemperatures(v))
        std::cerr << i << '\t';
    std::cerr << "\n";
    v = {30, 40, 50, 60};
    for (auto i : s.dailyTemperatures(v))
        std::cerr << i << '\t';
    std::cerr << "\n";
    return 0;
}