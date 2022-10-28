/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int max_length{0};
        std::unordered_set<char> set;
        int end{0};
        int start{0};
        while (end < s.size())
        {
            if (set.count(s[end]))
            {
                max_length = max_length > set.size() ? max_length : set.size();

                while (s[start] != s[end])
                {
                    set.erase(s[start++]);
                }
                ++start;
                // set.insert(s[end++]);
                ++end;
            }
            else
            {
                set.insert(s[end++]);
            }
        }
        return max_length > set.size() ? max_length : set.size();
    }
};
// @lc code=end

int main()
{
    Solution s;
    std::cerr << s.lengthOfLongestSubstring("abcabcbb");
    std::cerr << s.lengthOfLongestSubstring("bbbbb");
    std::cerr << s.lengthOfLongestSubstring("pwwkew");
    std::cerr << s.lengthOfLongestSubstring("dvdf");
    return 0;
}