/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
// @lc code=start
class Solution
{
public:
    std::vector<int> findAnagrams(std::string s, std::string p)
    {
        int length = p.size();
        if (s.size() < length)
            return {};
        std::unordered_map<char, int> s_letter_count;
        std::unordered_map<char, int> p_letter_count;
        std::vector<int> result;
        for (int i{0}; i < length; ++i)
        {
            p_letter_count[p[i]] += 1;
        }
        for (int i{0}; i < length - 1; ++i)
        {
            s_letter_count[s[i]] += 1;
        }

        for (int i{0}; i <= s.size() - length; ++i)
        {
            s_letter_count[s[i + length - 1]] += 1;
            bool flag{true};
            for (auto [key, value] : p_letter_count)
            {
                if (s_letter_count[key] != value)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                result.push_back(i);
            }
            s_letter_count[s[i]] -= 1;
        }
        return result;
    }
};
// @lc code=end
int main()
{
    std::string s{"aaaaaaaaaa"};
    std::string p{"aaaaaaaaaa"};
    return 0;
}

s =
"aaaaaaaaaa"
p =
"aaaaaaaaaaaaa"