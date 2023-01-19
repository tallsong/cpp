/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */
#include <string>
#include <iostream>
#include <unordered_map>
#include<unordered_set>
// @lc code=start
class Solution
{
public:
    bool isIsomorphic(std::string s, std::string t)
    {
        std::unordered_map<char, char> hashtable;
        std::unordered_set<char> set;
        for (int i{0}; i < s.size(); ++i)
        {
            if (hashtable.count(s[i]))
            {

                if (hashtable[s[i]] != t[i] )
                    return false;
            }
            else
            {
                if(set.count(t[i]))
                    return false;
                hashtable[s[i]] = t[i];

                set.insert(t[i]);
            }
        }
        return true;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.isIsomorphic("badc", "baba");
    return 0;
}