/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
// @lc code=start
class Solution
{
public:
    std::vector<int> partitionLabels(std::string s)
    {
        std::unordered_map<char, int> last;
        for (int i{0}; i < s.size(); ++i)
        {
            last[s[i]] = i;
        }

        std::vector<int> result;
        int start{0};
        int end{0};
        for (int i{0}; i < s.size(); ++i)
        {
            end = std::max(end, last[s[i]]);

            if (i == end)
            {

                result.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};
// @lc code=end

int main()
{
    std::string s{"ababcbacadefegdehijhklij"};
    Solution solution;
    auto n{solution.partitionLabels(s)};
    return 0;
}