/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <unordered_map>
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
        std::unordered_map<int, int> count;
        for (auto num : nums)
        {
            ++count[num];
        }

        auto compare = [&count](int x, int y)
        {
            return count[x] > count[y];
        };

        std::priority_queue<int, std::vector<int>, decltype(compare)> heap(compare);

        for (auto [key, value] : count)
        {
            heap.push(key);
            if (heap.size() > k)
                heap.pop();
        }

        std::vector<int> result(k);

        while (k > 0)
        {

            result[--k] = heap.top();
            heap.pop();
        }

        return result;
    }
};

// @lc code=end

int main()
{
    Solution s;
    std::vector<int> v{1, 1, 1, 2, 2, 3};
    s.topKFrequent(v, 2);
    return 0;
}