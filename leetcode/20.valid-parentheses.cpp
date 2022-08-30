/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include <stack>
#include <unordered_map>

// @lc code=start
class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> stack;
        std::unordered_map<char, char> map;
        map[')'] = '(';
        map[']'] = '[';
        map['}'] = '{';
        for (auto c : s)
        {
            if (map.count(c))
            {
                if (stack.empty())
                    return false;
                if (stack.top() == map[c])
                    stack.pop();
                else
                {

                    return false;
                }
            }
            else
            {
                stack.push(c);
            }
        }
        if (stack.empty())
        {
            return true;
        }
        else
        {

            return false;
        }
    }
};
// @lc code=end
