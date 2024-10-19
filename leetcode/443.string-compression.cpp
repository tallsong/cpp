/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
class Solution
{
public:
    int compress(vector<char>& chars)
    {
        int res = 0;
        int i{0};
        while (i < chars.size())
        {
            int length{1};
            while (i + length < chars.size() && chars[i] == chars[i + length])
                ++length;
            chars[res++] = chars[i];
            if (length > 1)
            {
                for (auto letter : to_string(length))
                {
                    chars[res++] = letter;
                }
            }
            i = i + length;
        }
        return res;
    }
};
// @lc code=end
