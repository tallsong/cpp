/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        auto compare = [](const vector<int>& p1, const vector<int>& p2)
        {
            return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> heap;

        for (const auto& point : points)
        {
            heap.push(point);
            if (heap.size() > k)
                heap.pop();
        }
        vector<vector<int>> result;

        while (heap.size())
        {
            result.push_back(heap.top());
            heap.pop();
        }

        return result;
    }
};
// @lc code=end

int main()
{
    return 0;
}