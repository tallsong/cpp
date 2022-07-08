#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left{0}, right{int(numbers.size())-1};
        while (left<right)
        {
            int temp{numbers.at(left)+numbers.at(right)};
            if(temp==target)
                return {left+1,right+1};
            if(temp<target)
                ++left;
            else
                --right;
        }
         
        return {0,0};
        
    }
};

int main()
{
   Solution s;
   vector<int> numbers{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};
   vector<int>  ans = s.twoSum(numbers,9);
    return 0;
}


