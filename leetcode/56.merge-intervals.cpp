/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

#include <vector>

class Solution_std
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval : intervals)
        {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0])
            {
                merged.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else
            {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};
// @lc code=start

class Solution
{
public:
    vector<vector<int>> merge(std::vector<std::vector<int>> &intervals)
    {
        std::vector<std::vector<int>> result;
        bool midified{false};
        for (auto &interval : intervals)
        {
            bool merged{false};
            for (auto &res : result)
            {
                if (interval.at(0) <= res.at(1) && interval.at(1) >= res.at(0))
                {
                    res.at(0) = std::min(res.at(0), interval.at(0));
                    res.at(1) = std::max(res.at(1), interval.at(1));
                    merged = true;
                    midified = true;
                    break;
                }
            }
            if (!merged)
            {
                result.emplace_back(interval);
            }
        }
        if (!midified)
        {
            return result;
        }
        return merge(result);
    }
};
// @lc code=end

int main()
{
    Solution s;

    return 0;
}
