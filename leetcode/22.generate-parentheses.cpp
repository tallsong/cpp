/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

#include <vector>
#include <string>

// @lc code=start
class Solution_force
{
public:
    bool check(const std::string &result)
    {
        int balance{0};
        for (auto letter : result)
        {
            if (letter == '(')
                ++balance;
            else
            {
                --balance;
                if (balance < 0)
                    return false;
            }
        }
        return balance == 0;
    }
    void helper(std::string &result, std::vector<std::string> &results, int n)
    {
        if (result.size() == n)
        {
            if (check(result))
            {
                results.push_back(result);
            }
            return;
        }
        result.push_back('(');
        helper(result, results, n);
        result.pop_back();

        result.push_back(')');
        helper(result, results, n);
        result.pop_back();
    }
    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> results;
        std::string result;
        helper(result, results, n * 2);
        return results;
    }
};
// @lc code=end

class Solution
{
public:
    void backtrack(std::vector<std::string> &results, std::string &result, int open, int close, int n)
    {
        if (result.size() == 2 * n)
        {

            results.push_back(result);
            return;
        }   

        if (open < n)
        {
            result += '(';
            backtrack(results, result, open + 1, close, n);
            result.pop_back();
        }
        if (close < open)
        {
            result += ')';
            backtrack(results, result, open, close + 1, n);
            result.pop_back();
        }
    }

    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> results;
        std::string result;
        backtrack(results, result, 0, 0, n);
        return results;
    }
};

int main()
{
    Solution s;
    s.generateParenthesis(32);
    return 0;
}