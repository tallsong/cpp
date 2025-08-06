#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();
        //where dp[i][j] represents the length of the longest common subsequence of text1[0:i] and text2[0:j]. eg text1[0:5] refer to first 5 letter(count is 5)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i{1}; i <= m; ++i)
        {
            for (int j{1}; j <= n; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

int main()
{

    Solution s;
    std::cerr << s.longestCommonSubsequence(string("abcde"), string("ace"));
    return 0;
}
