
/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

#include <iostream>
#include <vector>
#include <unordered_map>

// @lc code=start
class Solution
{

public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (!digits.size())
            return {};

        std::unordered_map<char, std::string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};

        std::vector<std::string> combintaions;
        std::string combination;
        helper(combintaions, combination, 0, digits, phoneMap);
        return combintaions;
    }
    void helper(std::vector<std::string> &combintaions, std::string &combination, int index, const std::string &digits, const std::unordered_map<char, std::string> &phoneMap)
    {
        if (index == digits.size())
        {
            combintaions.push_back(combination);
        }
        else
        {

            for (auto letter : phoneMap.at(digits.at(index)))
            {
                combination.push_back(letter);
                helper(combintaions, combination, index + 1, digits, phoneMap);
                combination.pop_back();
            }
        }
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.letterCombinations("23423423432423");
    return 0;
}
