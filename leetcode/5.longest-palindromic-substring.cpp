/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <utility>
// using namespace std;
// dynamic program
class Solution_dp
{
public:
    std::string longestPalindrome(std::string s)
    {
        std::string result{""};
        int length = s.size();
        std::vector<std::vector<bool>> dp(length, std::vector<bool>(length, true));

        for (int start{length - 1}; start >= 0; --start)
        {
            for (int end{start}; end < length; ++end)
            {

                if (start == end || (s[start] == s[end] && dp[start + 1][end - 1]))
                {
                    dp[start][end] = true;
                    result = result.length() > end - start + 1 ? result : s.substr(start, end - start + 1);
                }
                else
                {
                    dp[start][end] = false;
                }
            }
        }
        return result;
    }
};

class Solution
{
public:
    std::pair<int, int> extend_center(const std::string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s.at(left) == s.at(right))
        {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }

    std::string longestPalindrome(std::string s)
    {
        int start{0};
        int end{0};
        for (size_t i{0}; i < s.size(); ++i)
        {
            auto [left1, right1]{extend_center(s, i, i)};
            auto [left2, right2]{extend_center(s, i, i + 1)};
            if (right1 - left1 > end - start)
            {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start)
            {
                start = left2;
                end = right2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};

// @lc code=end

int main()
{
    Solution_dp solution;
    std::string s{"cbbd"};
    std::cerr << solution.longestPalindrome(s);
    return 0;
}