/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <utility>
// @lc code=start

class Solution_std
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        if (target == "0000")
        {
            return 0;
        }

        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000"))
        {
            return -1;
        }

        auto num_prev = [](char x) -> char
        {
            return (x == '0' ? '9' : x - 1);
        };
        auto num_succ = [](char x) -> char
        {
            return (x == '9' ? '0' : x + 1);
        };

        // 枚举 status 通过一次旋转得到的数字
        auto get = [&](string &status) -> vector<string>
        {
            vector<string> ret;
            for (int i = 0; i < 4; ++i)
            {
                char num = status[i];
                status[i] = num_prev(num);
                ret.push_back(status);
                status[i] = num_succ(num);
                ret.push_back(status);
                status[i] = num;
            }
            return ret;
        };

        queue<pair<string, int>> q;
        q.emplace("0000", 0);
        unordered_set<string> seen = {"0000"};

        while (!q.empty())
        {
            auto [status, step] = q.front();
            q.pop();
            for (auto &&next_status : get(status))
            {
                if (!seen.count(next_status) && !dead.count(next_status))
                {
                    if (next_status == target)
                    {
                        return step + 1;
                    }
                    q.emplace(next_status, step + 1);
                    seen.insert(move(next_status));
                }
            }
        }

        return -1;
    }
};

class Solution
{
public:
    int openLock(std::vector<std::string> &deadends, std::string target)
    {
        if (target == "0000")
            return 0;
        std::unordered_set<std::string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000"))
            return -1;
        auto num_prev = [](char num) -> char
        {
            return num == '0' ? '9' : num - 1;
        };
        auto num_next = [](char num) -> char
        {
            return num == '9' ? '0' : num + 1;
        };

        auto get = [&](std::string &target) -> std::vector<std::string>
        {
            std::vector<std::string> result;
            for (size_t i{0}; i < target.size(); ++i)
            {
                char num{target.at(i)};
                target.at(i) = num_prev(num);
                result.push_back(target);
                target.at(i) = num_next(num);
                result.push_back(target);
                target.at(i) = num;
            }
            return result;
        };

        std::unordered_set<std::string> seen{"0000"};
        std::queue<std::pair<std::string, int>> q;
        q.emplace(std::pair{"0000", 0}); // emplace not push
        while (!q.empty())
        {
            auto cur{q.front()};
            q.pop();
            for (auto &&next_position : get(cur.first))
            {
                if (next_position == target)
                    return cur.second + 1;

                if (!dead.count(next_position) && !seen.count(next_position))
                {

                    q.emplace(std::pair{next_position, cur.second + 1});
                    seen.insert(next_position);
                }
            }
        }

        return -1;
    }
};

// @lc code=end

int main()
{
    return 0;
}