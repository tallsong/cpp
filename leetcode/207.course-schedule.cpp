/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
// @lc code=start
class Solution_dfs
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


class Solution
{

public:
    std::unordered_map<int, int> hash;
    std::vector<int> order;
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
    {
        hash.clear();
        order.clear();
        for (auto prerequisite : prerequisites)
        {
            if (auto course = prerequisite[0]; hash.count(course))
            {
                hash[course] += 1;
            }
            else
            {
                hash[course] = 1;
            }
        }
        std::queue<int> q;
        for (int i{0}; i < numCourses; ++i)
        {
            if (!hash.count(i))
            {
                q.push(i);
                order.push_back(i);
            }
        }
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            for (auto prerequisite : prerequisites)
            {
                if (top == prerequisite[1])
                {
                    hash[prerequisite[0]] -= 1;
                    if (0 == hash[prerequisite[0]])
                    {
                        q.push(prerequisite[0]);
                        order.push_back(prerequisite[0]);
                    }
                }
            }
        }
        return order.size() == numCourses;
    }
};

// @lc code=end

int main()
{
    return 0;
}