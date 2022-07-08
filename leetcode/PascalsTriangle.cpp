#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result(numRows);
        for (int row{0}; row < numRows; ++row)
        {
            vector<int> temp(row+1);
            for (int column{0}; column <=row; ++column)
            {
                int first_row = row - 1;
                if (first_row < 0 || column == 0 || column ==row )
                {
                    temp.at(column)=1;
                }
                else
                {
                    temp.at(column) = result.at(row-1).at(column-1)  + result.at(row-1).at(column);
                }
            }
            result.at(row) = temp;
        }
        return result;
    }
};




int main()
{
    Solution s;
    vector<vector<int>> resut{s.generate(5)};
    return 0;

}