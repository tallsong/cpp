/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

#include <vector>
#include <iostream>
#include <unordered_set>
// @lc code=start
class Solution
{
public:
    void setZeroes(std::vector<std::vector<int>> &matrix)
    {
        auto m{matrix.size()};
        auto n{matrix.at(0).size()};
        std::unordered_set<int> rows;
        std::unordered_set<int> columns;
        for (int i{0}; i < m; ++i)
        {
            for (int j{0}; j < n; ++j)
            {
                if (!matrix.at(i).at(j))
                {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        for (auto row : rows)
        {
            for (int index{0}; index < n; ++index)
                matrix.at(row).at(index) = 0;
        }
        for (auto column : columns)
        {
            for (int index{0}; index < m; ++index)
                matrix.at(index).at(column) = 0;
        }
    }
};
// @lc code=end
int main()
{
    Solution s;
    std::vector<std::vector<int>> v1{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    s.setZeroes(v1);
    return 0;
}