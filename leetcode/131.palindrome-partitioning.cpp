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
    void dfs(std::vector<std::vector<std::string>> &result, std::vector<std::string> &current_strings, const std::string &s, int start, std::vector<std::vector<bool>> &dp)
    {
        if (start >= s.size())
        {
            result.push_back(current_strings);
        }
        else
        {

            for (int end{start}; end < s.size(); ++end)
            {
                // if (end - start < 1 || (s[start] == s[end] && dp[start + 1][end - 1]))
                if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1]))
                {
                    dp[start][end] = true;
                    current_strings.push_back(s.substr(start, end - start + 1));
                    dfs(result, current_strings, s, end + 1, dp);
                    current_strings.pop_back();
                }
            }
        }
    }
    std::vector<std::vector<std::string>> partition(std::string s)
    {
        int n = s.size();
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> current_strings;
        std::vector<std::vector<bool>> dp(std::vector(n, std::vector(n, false)));
        dfs(result, current_strings, s, 0, dp);
        return result;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.partition("aab");
    return 0;
}