
/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

#include <iostream>
#include <unordered_map>
#include <vector>

// @lc code=start
class Solution
{

    std::unordered_map<char, std::string> hash{

        {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},

        }};
    std::vector<std::string> combinations;
    std::string combination;

public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (!digits.size())
        {
            return {};
        }
        helper(0, digits);
        return combinations;
    }

    void helper(int index, std::string& digits)
    {
        if (combination.size() == digits.size())
        {
            combinations.push_back(combination);
            return;
        }
        for (auto letter : hash.at(digits.at(index)))
        {
            combination.push_back(letter);
            helper(index + 1, digits);
            combination.pop_back();
        }
    }
};
// @lc code=end

int main()
{
    Solution s;
    for (auto& com : s.letterCombinations("234"))
    {
        std::cerr << com << '\n';
    }
    return 0;
}
