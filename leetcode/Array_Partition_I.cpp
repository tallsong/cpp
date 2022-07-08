#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        std::sort(nums.begin(),nums.end());
        int result{0};
        for(int i{0};i<nums.size();i+=2)
        {
            result+=nums.at(i);
        }
        return result;
    }
};

int main()
{
    vector<int> nums{6,2,6,5,1,2};
    Solution s;
    std::cerr<<s.arrayPairSum(nums);
    return 0;
}
