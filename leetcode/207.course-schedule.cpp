/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

#include <unordered_map>
#include <vector>
#include <iostream>
// @lc code=start
class Solution
{
private:
    std::vector<std::vector<int>> edges;
    std::vector<int> visted;
    bool valid{true};

public:
    void dfs(int u)
    {

        visted[u] = 1;
        for (const auto i : edges[u])
        {
            if (visted[i] == 0)
            {

                dfs(i);
                if (!valid)
                    return;
                else if (visted[1])
                {
                    /* code */
                }
            }

            else if (visted[i] == 1)
            {
                valid = false;
                return;
            }
        }

        visted[u] = 2;
    }
    bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        visted.resize(numCourses);

        for (const auto &prerequisite : prerequisites)
        {
            edges[prerequisite[1]].push_back(prerequisite[0]);
        }

        for (int i{0}; i < numCourses && valid; ++i)
        {
            if (!visted[i])
                dfs(i);
        }
        return valid;
    }
};

// @lc code=end
