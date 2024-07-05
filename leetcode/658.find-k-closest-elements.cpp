/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
    int find_upright(std::vector<int>& arr, int x)
    {
        int start{0};
        auto end{arr.size() - 1};
        while (start + 1 < end)
        {
            auto mid{start + (end - start) / 2};
            if (arr[mid] >= x)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        if (arr[start] >= x)
            return start;
        return end;
    }

public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        auto right = find_upright(arr, x);
        auto left = right - 1;
        auto start = left;

        std::vector<int> result;
        while (result.size() < k)
        {
            if (left < 0)
            {

                result.push_back(arr[right++]);
                continue;
            }
            if (right >= arr.size())
            {
                result.push_back(arr[left--]);
                continue;
            }
            if (std::abs(arr[left] - x) <= std::abs(arr[right] - x))
            {
                result.push_back(arr[left--]);
            }
            else
            {
                result.push_back(arr[right++]);
            }
        }
        std::sort(result.begin(), result.end());

        return result;
    }
};
// @lc code=end

int main()
{
    std::vector<int> arr{1, 2, 3, 4, 5};
    Solution s;
    for (auto element : s.findClosestElements(arr, 4, 3))
    {
        std::cerr << element << '\t';
    }
}
