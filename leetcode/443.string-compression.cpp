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
        int count{0};
        for (int i{0}; i < chars.size(); ++i)
        {
            int j{i};
            while (j + 1 < chars.size() && chars[j] == chars[j + 1])
            {
                ++j;
            }
            chars[count] = chars[i];
            ++count;
            int start{count};
            int temp{j - i + 1};
            if (temp > 1)
            {

                while (temp)
                {
                    // chars[count++] = '0' + temp % 10;
                    chars[count++] = static_cast<char>(temp % 10);
                    temp /= 10;
                }
                std::reverse(chars.begin() + start, chars.begin() + count);
            }
            i = j;
        }
        return count;
    }
};
// @lc code=end

int main()
{
    Solution s;
    std::vector<char> chars{'a', 'a', 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'c'};
    std::cerr << s.compress(chars) << '\n';
    for (auto letter : chars)
    {
        std::cerr << letter;
    }

    return 0;
}
