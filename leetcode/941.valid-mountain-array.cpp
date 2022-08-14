/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

#include <vector>
#include <iostream>

// @lc code=start
class Solution
{
public:
    bool validMountainArray(std::vector<int> &arr)
    {
        if (arr.size() < 3)
        {
            return false;
        }
        int i{0};
        while ((i + 1 < arr.size()) && (arr.at(i + 1) > arr.at(i)))
        {
            ++i;
        }
        if (i == arr.size() - 1 || i == 0)
            return false;

        while (i + 1 < arr.size() && arr.at(i + 1) < arr.at(i))
            ++i;
        return (i == arr.size() - 1);
    }
};
// @lc code=end

int main()
{
    Solution s;
    std::vector v{0, 3, 2, 1};
    std::cerr << s.validMountainArray(v);
}