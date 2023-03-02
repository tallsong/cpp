/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         int n = int(s.length()), res = 0;
//         unordered_map<char, int> mp;

//         for (int j = 0, i = 0; j < n; j++)
//         {
//             if (mp[s[j]] > 0)
//             {
//                 i = max(mp[s[j]], i);
//             }
//             res = max(res, j - i + 1);
//             mp[s[j]] = j + 1;
//         }
//         return res;
//     }
// };

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {

        int string_size = s.size();
        int left{0};
        int right{0};
        int max_length{0};

        std::unordered_map<char, int> cache;

        while (right < string_size)
        {
            while (right < string_size && !cache[s[right]])
            {
                cache[s[right++]]++;
            }
            max_length = max_length > (right - left) ? max_length : (right - left);

            while (cache[(s[right])])
            {
                --cache[s[left++]];
            }
        }
        return max_length > (right - left) ? max_length : (right - left);
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