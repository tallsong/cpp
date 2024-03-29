#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    vector<int> ç(vector<vector<int>> &matrix)
    {
        if (!matrix.size())
        {
            return {};
        }
        if (!matrix.at(0).size())
        {
            return {};
        }
        unsigned long rows{matrix.size()};
        unsigned long columns{matrix.at(0).size()};

        vector<vector<bool>> visited(rows, vector<bool>(columns, false));
        vector<int> order(rows * columns);

        int row{0};
        int column{0};
        int direction_index{0};
        for (int i{0}; i < rows * columns; ++i)
        {
            order.at(i) = matrix.at(row).at(column);
            visited.at(row).at(column) = true;
            int next_row{row + directions[direction_index][0]};
            int next_column{column + directions[direction_index][1]};
            if (next_row < 0 || next_row >= rows || next_column < 0 || next_column >= columns || visited.at(next_row).at(next_column))
            {
                direction_index = (direction_index + 1) % 4;
            }
            row = {row + directions[direction_index][0]};
            column = {column + directions[direction_index][1]};
        }
        return order;
    }
};

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result(numRows);
        for (int row{0}; row < numRows; ++row)
        {
            vector<int> temp(row+1);
            for (int column{0}; column < row; ++column)
            {
                int first_row = row - 1;
                if (first_row < 0 || column == 0 || column ==row-1 )
                {
                    temp.at(column)=0;
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

int test_spiralOrder()
{
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    spiralOrder s;
    vector<int> result = s.spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result.at(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}


int main()
{
    Solution s;
    vector<vector<int>> resut{s.generate(5)};
    return 0;

}