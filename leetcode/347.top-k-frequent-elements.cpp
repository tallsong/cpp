/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <map>
#include <queue>
#include <iostream>

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        if (k == nums.size())
        {
            return nums;
        }

        std::map<int, int> counter_map;
        for (auto num : nums)
        {
            counter_map[num]++;
        }

        auto compare{
            [&counter_map](int x, int y)
            {
                return counter_map[x] > counter_map[y];
            }};
        std::priority_queue<int, std::vector<int>, decltype(compare)> heap(compare);

        for (auto[first,second]:counter_map)
        {
            heap.push(first);
            if (heap.size() > k)
                heap.pop();
        }
        std::vector<int> result(k);
         while (k > 0)
        {
            result[--k] = heap.top();
            heap.pop();
        }
        return nums;
    }
};

// @lc code=end

int main()
{
    Solution s;
    std::vector<int > v{1,1,1,2,2,3};
    s.topKFrequent(v,2);
    return 0;
}