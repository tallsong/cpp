#include <iostream>
#include <vector>
#include <numeric>
#include <utility>
using namespace std;
// 189
class Solution
{
public:
    void reverse(vector<int> & nums, int start, int end)
    {
        while (start < end)
        {
            std::swap(nums.at(start++), nums.at(end--));
        }
    }
    void rotate(vector<int> &nums, int k)
    {
        this->reverse(nums,0, nums.size()-1);
        this->reverse(nums,0,k%nums.size()-1);
        this->reverse(nums,k%nums.size(),nums.size()-1);

    }
};

int main()
{
    vector<int> mastrx{1, 2, 3, 4, 5, 6, 7};
    Solution s;
    s.rotate(mastrx, 3);
    for (auto i : mastrx)
    {
        std::cerr << i << '\t';
    }

    return 0;
}
