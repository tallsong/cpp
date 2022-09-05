#include <iostream>
#include <vector>

class Solution
{
public:
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
    {
        int m{int(matrix.size())};
        int n{int(matrix.at(0).size())};
        std::vector<int> result(m*n);
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n));
        int i{0};
        int j{0};
        int direction{0};
        for (int index{0}; index < m * n; ++index)
        {
            result.at(index) = matrix.at(i).at(j);
            visited.at(i).at(j) = true;
            int ni{i + directions[direction][0]};
            int nj{j + directions[direction][1]};
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited.at(ni).at(nj))
            {
                i = ni;
                j = nj;
            }
            else
            {
                direction = (direction + 1) % 4;
                i={i + directions[direction][0]};
                j = {j + directions[direction][1]};
            }
        }
        return result;
    }
};

int main()
{
    std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Solution s;
    std::vector<int> result = s.spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result.at(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}
