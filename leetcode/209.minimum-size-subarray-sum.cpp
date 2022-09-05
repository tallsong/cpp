/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

#include <limits>
#include <vector>
#include <iostream>
#include <numeric>

// @lc code=start
class Solution
{
public:
    int minSubArrayLen_brute_force(int s, std::vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        int ans = INT_MAX;
        std::vector<int> sums(n);
        sums[0] = 0;
        for (int i{1}; i < n; ++i)
        {
            sums[i] = (sums[i - 1] + nums.at(i - 1));
        }

        for (int i{0}; i < n; ++i)
        {
            for (int j{i}; j < n; ++j)
            {

                int temp_sum{sums[j] - sums[i] + nums.at(j)};
                if (temp_sum >= s)
                {
                    ans = (j - i + 1) < ans ? (j - i + 1) : ans;
                    break;
                }
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
    int minSubArrayLen(int target, std::vector<int> &nums)
    {
        int result = INT_MAX;
        int start{0};
        int end{0};
        auto length{nums.size()};
        int sum{0};
        while (end < length)
        {
            sum += nums.at(end);
            while (sum >= target)
            {
                int temp{end - start + 1};
                result = std::min(result, temp);
                sum -= nums.at(start++);
            }
            ++end;
        }
        return result == INT_MAX ? 0 : result;
    }
};
// @lc code=end

// 209

int main()
{
    Solution s;
    std::vector<int> numbers;
    numbers={2,3,1,2,4,3};
    std::cout << s.minSubArrayLen(7, numbers);
    std::cerr<<'\n';
    numbers={1, 1, 1, 1, 1, 1, 1, 1};
    std::cout << s.minSubArrayLen(11, numbers);
    std::cerr<<'\n';
    return 0;
}