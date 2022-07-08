#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int max_consecutive{0};

        int start{0};
        while (start < nums.size())
        {
            int temp_result = 0;
            int temp_point(start);
            while (temp_point < nums.size() && nums.at(temp_point) == 1)
            {
                ++temp_result;
                ++temp_point;
            }
            max_consecutive = max_consecutive > temp_result ? max_consecutive : temp_result;
            start = ++temp_point;
        }
        return max_consecutive;
    }
};

int main()
{
    Solution s;
    vector<int> numbers{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::cout << "result is " << s.findMaxConsecutiveOnes(numbers);

    return 0;
}
