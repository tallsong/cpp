#include <limits>
#include <vector>
#include <iostream>
#include <numeric>
// 209
using namespace std;
class Solution
{
public:
    int minSubArrayLen_brute_force(int s, vector<int> &nums)
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
    int minSubArrayLen(int target, vector<int> &nums)
    {
        auto n{nums.size()};
        int result{INT_MAX};
        int sum{0};
        int start{0};
        int end{0};
        while (end < n)
        {
            sum += nums.at(end);
            while (sum >= target)
            {
                int current_length{end-start+1};
                result=result<current_length?result:current_length;
                sum-=nums.at(start++);
            }
            end++;
        }
        return result==INT_MAX?0:result;
    }
};

int main()
{
    Solution s;
    vector<int> numbers{1,1,1,1,1,1,1,1};
    std::cout << s.minSubArrayLen(11, numbers);
    return 0;
}
