/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start

class Solution
{
    static constexpr int factor[3] = {2, 3, 5};

public:
    // heap and hash
    int nthUglyNumber(int n)
    {
        unordered_set<long> seen;
        priority_queue<long, vector<long>, greater<long>> heap;
        heap.push(1);
        seen.insert(1);
        for (int i{0}; i < n - 1; ++i)
        {
            long top = heap.top();
            heap.pop();
            for (int i{0}; i < 3; ++i)
            {
                long element = factor[i] * top;
                if (!seen.count(element))
                {

                    heap.push(element);
                    seen.insert(element);
                }
            }
        }

        return heap.top();
    }
};

class Solution_dp
{
public:
    int nthUglyNumber(int n)
    {
        std::vector<int> dp(n);

        dp[0] = 1;
        int l2 = 0;
        int l3 = 0;
        int l5 = 0;
        for (int i{1}; i < n; ++i)
        {
            dp[i] = min(min(dp[l2] * 2, dp[l3] * 3), dp[l5] * 5);
            if (dp[i] == dp[l2] * 2)
                ++l2;
            if (dp[i] == dp[l3] * 3)
                ++l3;
            if (dp[i] == dp[l5] * 5)
                ++l5;
        }
        return dp.back();
    }
};

// @lc code=end

int main()
{
    return 0;
}