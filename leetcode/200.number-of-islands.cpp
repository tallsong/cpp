/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
#include <queue>
#include <vector>
#include <utility>
#include <iostream>
#include <stack>
// @lc code=start
class Solution_BDS
{
public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        int result{0};

        size_t m{grid.size()};

        if (!m)
            return 0;
        size_t n{grid.at(0).size()};
        if (!n)
            return 0;
        for (int i{0}; i < m; ++i)
        {
            for (int j{0}; j < n; ++j)
            {
                if (grid.at(i).at(j) == '1')
                {
                    ++result;
                    grid.at(i).at(j) == '0';
                    std::queue<std::pair<int, int>> q;
                    q.push({i, j});

                    while (!q.empty())
                    {
                        auto pair{q.front()};
                        q.pop();
                        auto first{pair.first};
                        auto second{pair.second};
                        if (first + 1 < m && grid.at(first + 1).at(second) == '1')
                        {
                            grid.at(first + 1).at(second) = '0';
                            q.push({first + 1, second});
                        }
                        if (first - 1 >= 0 && grid.at(first - 1).at(second) == '1')
                        {
                            grid.at(first - 1).at(second) = '0';
                            q.push({first - 1, second});
                        }
                        if (second + 1 < n && grid.at(first).at(second + 1) == '1')
                        {
                            grid.at(first).at(second + 1) = '0';
                            q.push({first, second + 1});
                        }
                        if (second - 1 >= 0 && grid.at(first).at(second - 1) == '1')
                        {
                            grid.at(first).at(second - 1) = '0';
                            q.push({first, second - 1});
                        }
                    }
                }
            }
        }
        return result;
    }
};
class Solution
{
public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        int result{0};

        size_t m{grid.size()};

        if (!m)
            return 0;
        size_t n{grid.at(0).size()};
        if (!n)
            return 0;
        for (int i{0}; i < m; ++i)
        {
            for (int j{0}; j < n; ++j)
            {
                if (grid.at(i).at(j) == '1')
                {
                    ++result;
                    grid.at(i).at(j) == '0';
                    std::stack<std::pair<int, int>> stack;
                    stack.push({i, j});

                    while (!stack.empty())
                    {
                        auto pair{stack.top()};
                        stack.pop();
                        auto first{pair.first};
                        auto second{pair.second};
                        if (first + 1 < m && grid.at(first + 1).at(second) == '1')
                        {
                            grid.at(first + 1).at(second) = '0';
                            stack.push({first + 1, second});
                        }
                        if (first - 1 >= 0 && grid.at(first - 1).at(second) == '1')
                        {
                            grid.at(first - 1).at(second) = '0';
                            stack.push({first - 1, second});
                        }
                        if (second + 1 < n && grid.at(first).at(second + 1) == '1')
                        {
                            grid.at(first).at(second + 1) = '0';
                            stack.push({first, second + 1});
                        }
                        if (second - 1 >= 0 && grid.at(first).at(second - 1) == '1')
                        {
                            grid.at(first).at(second - 1) = '0';
                            stack.push({first, second - 1});
                        }
                    }
                }
            }
        }
        return result;
    }
};

// @lc code=end

int main()
{
    std::vector<std::vector<char>> v{{'1', '1', '1', '1', '0'},
                                     {'1', '1', '0', '1', '0'},
                                     {'1', '1', '0', '0', '0'},
                                     {'0', '0', '0', '0', '0'}};
    std::vector<std::vector<char>> v2{{'1', '1', '1'},
                                      {'0', '1', '0'},
                                      {'1', '1', '1'}};
    Solution s;
    std::cerr << s.numIslands(v2);

    return 0;
}