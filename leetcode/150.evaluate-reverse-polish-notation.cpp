/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

#include <string>
#include <stack>
#include <vector>
#include <iostream>
// @lc code=start
class Solution
{
public:
    bool isOperator(const std::string &token)
    {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
    int evalRPN(std::vector<std::string> &tokens)
    {
        std::stack<int> stack;
        for (auto &token : tokens)
        {
            if (isOperator(token))
            {
                auto num1 = stack.top();
                stack.pop();
                auto num2 = stack.top();
                stack.pop();

                switch (token.at(0))
                {
                case '+':
                    stack.push(num1 + num2);
                    break;
                case '-':
                    stack.push(num2 - num1);
                    break;
                case '*':
                    stack.push(num1 * num2);
                    break;
                case '/':
                    stack.push(num2 / num1);
                    break;

                default:
                    break;
                }
            }
            else
            {
                stack.push(std::atoi(token.c_str()));
            }
        }
        return stack.top();
    }
};

// @lc code=end

int main()
{
    Solution s;
    std::vector<std::string> v{"4", "13", "5", "/", "+"};
    std::cerr << s.evalRPN(v);

    return 0;
}