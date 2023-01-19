/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */
#include <string>
#include <unordered_map>
// @lc code=start
class Solution
{
public:
    int firstUniqChar(std::string s)
    {
        std::unordered_map<char, int> hashtable;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            hashtable[s[i]]++;
        }
        for (int i{0}; i < s.size(); ++i)
        {
            if (hashtable[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end
