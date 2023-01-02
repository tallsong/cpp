/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */
#include <vector>
#include <iostream>

// @lc code=start
class Solution
{
public:
    int compress(std::vector<char> &chars)
    {
        int length = chars.size();
        int wirte{0};
        int left{0};
        for (int read{0}; read < chars.size(); ++read)
        {
            if (read == length - 1 || chars[read] != chars[read + 1])
            {
                chars[wirte++] = chars[read];
                int sub_length = read - left + 1;
                if (sub_length > 1)
                {
                    int anchor{wirte};
                    while (sub_length > 0)
                    {
                        chars[wirte++] = sub_length % 10 + '0';
                        sub_length /= 10;
                    }
                    std::reverse(&chars[anchor], &chars[wirte]);
                }

                left = read + 1;
            }
        }
        return wirte;
    }
};

// @lc code=end

int main()
{
    Solution s;
    std::vector<char> chars{'a', 'a', 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'c'};
    std::cerr << s.compress(chars);
    return 0;
}