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
        int left{0};
        int write{0};
        int length = chars.size();
        for (int read{0}; read < length; ++read)
        {
            if (read == length - 1 || chars[read] != chars[read + 1])
            {
                chars[write++] = chars[read];
                int sub_length{read - left + 1};
                if (sub_length > 1)
                {
                    int anchor = write;
                    while (sub_length > 0)
                    {
                        chars[write++] = sub_length % 10 + '0';
                        sub_length /= 10;
                    }
                    std::reverse(&chars[anchor], &chars[write]);
                }

                left = read + 1;
            }
        }
        return write;
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