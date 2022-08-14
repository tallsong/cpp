#include <iostream>
#include <vector>
#include <numeric>
#include <utility>
using namespace std;
// 119
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {

        vector<int> result{1};
        for (int i{1}; i < rowIndex + 1; ++i)
        {
            vector<int> temp(i + 1);
            for (int j{0}; j <= i; ++j)
            {
                if (j == 0 || j >= result.size())
                {

                    temp[j] = 1;
                }
                else
                {
                    temp[j] = result.at(j - 1) + result.at(j);
                }
            }
            result = temp;
        }
        return result;
    }
};

int main()
{
    vector<int> mastrx{1, 2, 3, 4, 5, 6, 7};
    Solution s;
    for (int row : s.getRow(3))
    {
        std::cerr << row << '\t';
    }

    return 0;
}
