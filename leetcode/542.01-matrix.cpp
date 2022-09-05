/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

#include <vector>
#include <iostream>
#include <utility>
#include <queue>

// @lc code=start
class Solution
{
private:
    static constexpr int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &mat)
    {
        size_t m{mat.size()};
        size_t n{mat.at(0).size()};

        std::vector<std::vector<int>> distance(m, std::vector<int>(n));
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n));
        std::queue<std::pair<size_t, size_t>> q;
        for (int i{0}; i < m; ++i)
        {
            for (int j{0}; j < n; ++j)
            {
                if (!mat.at(i).at(j))
                {

                    visited.at(i).at(j) = true;
                    q.emplace(i, j);
                }
            }
        }
        while (!q.empty())
        {
            auto [row, column]{q.front()};
            q.pop();
            for (int i{0}; i < 4; ++i)
            {
                auto new_row{row + directions[i][0]};
                auto new_column{column + directions[i][1]};
                if (new_row >= 0 && new_row < m && new_column >= 0 && new_column < n && !visited.at(new_row).at(new_column))
                {
                    visited.at(new_row).at(new_column) = true;
                    distance.at(new_row).at(new_column) = distance.at(row).at(column) + 1;
                    q.emplace(new_row, new_column);
                }
            }
        }

        return distance;
    }
};
// @lc code=end

int main()
{
    Solution s;
    std::vector<std::vector<int>> v{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    s.updateMatrix(v);
    return 0;
}