/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

#include <vector>
#include <iostream>
#include <utility>
#include <queue>
#include <climits>
// @lc code=start
class Solution
{
private:
    static constexpr int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        std::queue<std::pair<int, int>> q;

        std::vector<std::vector<int>> distances(m, std::vector(n, 0));
        for (int i{0}; i < m; ++i)
        {
            for (int j{0}; j < n; ++j)
            {
                if (mat[i][j])
                {
                    distances[i][j] = INT_MAX;
                }
                else
                {
                    q.emplace(i, j);
                }
            }
        }

        int count{0};
        while (!q.empty())
        {
            ++count;
            int size = q.size();
            for (int i{0}; i < size; ++i)
            {

                auto dirction = q.front();
                q.pop();
                for (int temp{0}; temp < 4; ++temp)
                {
                    int new_row = dirction.first + directions[temp][0];
                    int new_column = dirction.second + directions[temp][1];
                    if (new_row >= 0 && new_row < m && new_column >= 0 && new_column < n && mat[new_row][new_column] != 0 && distances[new_row][new_column] == INT_MAX)
                    {
                        distances[new_row][new_column] = count;
                        q.emplace(new_row, new_column);
                    }
                }
            }
        }

        return distances;
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