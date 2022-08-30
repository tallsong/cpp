/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

#include <string>
#include <iostream>
#include <stack>
// @lc code=start
class Solution
{
public:
    std::string decodeString(std::string s)
    {
        std::string result;
        std::stack<std::pair<int, std::string>> stack;

        size_t i{0};
        while (i < s.size())
        {
            if (isdigit(s.at(i)))
            {
                int length{0};
                while (isdigit(s.at(i + length)))
                {
                    ++length;
                }
                int repeated{std::stoi(s.substr(i, length))};
                i = length + i + 1;
                length = 0;
                while (isalpha(s.at(i + length)))
                {
                    ++length;
                }
                std::string temp{s.substr(i, length)};
                stack.push({repeated, temp});
                i += length;
            }
            else
            {
                if (s.at(i) == ']')
                {

                    auto [times, str] = stack.top();
                    stack.pop();
                    if (stack.empty())
                    {
                        for (int i{0}; i < times; ++i)
                        {
                            result += str;
                        }
                    }
                    else
                    {
                        auto p = stack.top();
                        stack.pop();
                        for (int i{0}; i < times; ++i)
                        {
                            p.second += str;
                        }
                        stack.push(p);
                    }
                }
                else
                {
                    if (stack.empty())
                    {
                        result += s.at(i);
                    }
                    else
                    {
                        auto p = stack.top();
                        stack.pop();

                        p.second += s.at(i);

                        stack.push(p);
                    }
                }
                ++i;
            }
        }
        return result;
    }
};
// @lc code=end

int main()
{
    // std::string s{"2[abc]3[cd]ef"};
    Solution solution;
    // std::cerr << solution.decodeString(s)<<'\n';

    std::cerr << solution.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef");
    return 0;
}

// zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef
// zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef