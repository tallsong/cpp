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
        auto n{s.size()};
        if (n < 2)
        {
            return s;
        }
        int start_position{0};
        int max_length{1};
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n));

        for (int i{0}; i < n; ++i)
        {
            dp.at(i).at(i) = true;
        }
        // iterate from short string to long string
        for (auto i{int(n - 1)}; i >= 0; --i)
        {
            for (auto j{i + 1}; j < n; ++j)
            {
                if (s.at(j) == s.at(i))
                {
                    if (j - i < 3)
                    {
                        dp.at(i).at(j) = true;
                    }
                    else
                    {

                        dp.at(i).at(j) = dp.at(i + 1).at(j - 1);
                    }
                }
                else
                {
                    dp.at(i).at(j) = false;
                }
                if (dp.at(i).at(j))
                {
                    int length{j - i + 1};
                    if (length > max_length)
                    {
                        max_length = length;
                        start_position = i;
                    }
                }
            }
        }

        return s.substr(start_position, max_length);
    }
};

class Solution
{
public:
    std::pair<int,int> extend_center(const std::string &s,int left, int right)
    {
        while(left>=0 && right<s.size() && s.at(left)==s.at(right))
        {
            left--;
            right++;
        }
        return {left+1,right-1};
    }

    std::string longestPalindrome(std::string s)
    {
        int start{0};
        int end{0};
        for(size_t i{0};i<s.size();++i)
        {
            auto[left1,right1]{extend_center(s,i,i)};
            auto[left2,right2]{extend_center(s,i,i+1)};
            if(right1-left1>end-start)
            {
                start=left1;
                end=right1;
            }
            if(right2-left2 > end-start)
            {
                start=left2;
                end=right2;
            }
        }

        return s.substr(start,end-start+1);
    }
};

// @lc code=end

int main()
{
    Solution solution;
    std::string s{"cbbd"};
    std::cerr << solution.longestPalindrome(s);
    return 0;
}