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
    static constexpr int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &mat)
    {
        size_t m{mat.size()};
        size_t n{mat.at(0).size()};
        std::vector<std::vector<int>> distance{m, std::vector<int>(n)};
        std::vector<std::vector<int>> seen{m, std::vector<int>(n)};
        std::queue<std::pair<size_t, size_t>> queue;
        for (size_t i{0}; i < m; ++i)
        {
            for (size_t j{0}; j < n; ++j)
            {  
                if (mat.at(i).at(j) == 0)
                {
                    seen.at(i).at(j) = 1;
                    queue.emplace(i, j);
                }
            }
        }

        while (!queue.empty())
        {
            auto [i, j] = queue.front();
            queue.pop();
            for (int index{0}; index < 4; ++index)
            {
                auto ni{i + directions[index][0]};
                auto nj{j + directions[index][1]};
                if (ni >= 0 && nj >= 0 && ni < m && nj < n && !seen.at(ni).at(nj))
                {
                    distance.at(ni).at(nj) = distance.at(i).at(j) + 1;
                    seen.at(ni).at(nj) = 1;
                    queue.emplace(ni, nj);
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
    std::vector<std::vector<int>> v{{0,0,0},{0,1,0},{1,1,1}};
    s.updateMatrix(v);
    return 0;
}