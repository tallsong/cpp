/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
#include <utility>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

//  https://leetcode.com/problems/word-break/
// @lc code=start

class Solution
{
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        std::unordered_set<std::string> set;
        for (auto &word : wordDict)
        {
            set.insert(word);
        }
        std::vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i{1}; i <= s.size(); ++i)
        {
            for (int j{0}; j < i; ++j)
            {
                if (dp[j] && set.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
// @lc code=end

int test1()
{
    Solution s;
    // std::string str{"applepenapple"};
    // std::vector<std::string>  v{"apple","pen"};
    std::string str{"leetcode"};
    std::vector<std::string> v{"leet", "code"};
    if (s.wordBreak(str, v))
    {
        std::cerr << "get!";
    }
    else
    {
        std::cerr << "no";
        return 0;
    }
}

int test2()
{
    Solution s;
    // std::string str{"applepenapple"};
    // std::vector<std::string>  v{"apple","pen"};
    std::string str{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"};
    std::vector<std::string> v{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    if (s.wordBreak(str, v))
    {
        std::cerr << "get!";
    }
    else
    {
        std::cerr << "on";
        return 0;
    }
}
int main()
{
    test1();
    test2();
    return 0;
}
