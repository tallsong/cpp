/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

#include <vector>
#include <queue>
#include <utility>
#include <iostream>
// @lc code=start
class Solution
{
private:
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    int orangesRotting(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int rotten_count{0};
        int fresh_count{0};
        std::queue<std::pair<int, int>> queue;
        for (int i{0}; i < m; ++i)
        {
            for (int j{0}; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    ++fresh_count;
                }
                if (grid[i][j] == 2)
                {
                    queue.push({i, j});
                    ++rotten_count;
                }
            }
        }
        if (!fresh_count)
            return 0;
        int minimum_number{0};
        int last{0};
        while (queue.size() != last)
        {
            last = queue.size();
            if (queue.size() == rotten_count + fresh_count)
                return minimum_number;
            ++minimum_number;
            int length = queue.size();
            for (int i{0}; i < length; ++i)
            {
                auto [row, column] = queue.front();
                queue.pop();
                queue.push({row, column});
                for (int j{0}; j < 4; ++j)
                {

                    auto new_row = row + directions[j][0];
                    auto new_column = column + directions[j][1];
                    if (new_column >= 0 && new_column < n && new_row >= 0 && new_row < m)
                    {
                        if (grid[new_row][new_column] == 1)
                        {
                            grid[new_row][new_column] = 2;
                            queue.push({new_row, new_column});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

int main()
{
    // std::vector<std::vector<int>> grid{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    std::vector<std::vector<int>> grid{{0}};
    Solution s;
    std::cerr << s.orangesRotting(grid);
    return 0;
}