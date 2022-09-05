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
#include<iostream>
// @lc code=start

class Solution_std
{
public:
    int openLock(std::vector<std::string> &deadends, std::string target)
    {
        if (target == "0000")
        {
            return 0;
        }

        std::unordered_set<std::string> dead(deadends.begin(), deadends.end());
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
        auto get = [&](std::string &status) -> std::vector<std::string>
        {
            std::vector<std::string> ret;
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

        std::queue<std::pair<std::string, int>> q;
        q.emplace("0000", 0);
        std::unordered_set<std::string> seen = {"0000"};

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
       

        return -1;
    }
};

// @lc code=end

int main()
{
    std::cerr<<'9'+1;
    return 0;
}