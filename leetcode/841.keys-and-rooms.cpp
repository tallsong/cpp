/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

#include <vector>
#include <unordered_set>
#include <queue>
// @lc code=start
class Solution
{
public:
    bool canVisitAllRooms(std::vector<std::vector<int>> &rooms)
    {
        std::unordered_set<int> visited{0};
        std::queue<std::vector<int>> q;
        q.emplace(rooms.at(0));
        while (!q.empty())
        {
            auto keys{q.front()};
            q.pop();
            for (auto key : keys)
            {
                if (!visited.count(key))
                {
                    q.emplace(rooms.at(key));
                    visited.insert(key);
                }
            }
        }
        return rooms.size() == visited.size();
    }
};
// @lc code=end


int main()
{
    Solution s;
    std::vector<std::vector<int>> rooms{{1},{2},{3},{}};
    return s.canVisitAllRooms(rooms);
    return 0;
}