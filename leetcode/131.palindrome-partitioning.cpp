/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    std::vector<std::vector<std::string>> partition(std::string s)
    {
        std::vector<std::vector<std::string>> result;
        std::vector<std::vector<bool>> dp(s.size(), std::vector(s.size(), false));
        std::vector<std::string> current_string;

        dfs(result, current_string, 0, s, dp);

        return result;
    }

    void dfs(std::vector<std::vector<std::string>> &result, std::vector<std::string> &current_string, const int start, const std::string &s, std::vector<std::vector<bool>> &dp)
    {
        if (start >= s.size())
            result.push_back(current_string);
        else
        {
            for (int end{start}; end < s.size(); ++end)
            {
                if (auto str{s.substr(start, end - start + 1)}; (s[start] == s[end]) && (end - start <= 2 || dp[start + 1][end - 1]))
                {
                    dp[start][end] = true;
                    current_string.push_back(str);
                    dfs(result, current_string, end + 1, s, dp);
                    current_string.pop_back();
                }
            }
        }
    }
};
// @lc code=end

int main()
{
    Solution s;
    auto a = s.partition("aab");
    return 0;
}