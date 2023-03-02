#include <iostream>
#include <vector>

class Solution
{
public:
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<bool>> visited(m, std::vector(n, false));
        std::vector<int> result(m * n);
        int x{0};
        int y{0};
        int direction{0};
        for (int i{0}; i < m * n; ++i)
        {
            result[i] = matrix[x][y];
            visited[x][y] = true;
            if (auto new_x{x + directions[direction][0]}, new_y{y + directions[direction][1]}; new_x < m && new_y < n && new_x >= 0 && new_y >= 0 && !visited[new_x][new_y])
            {
                x = new_x;
                y = new_y;
            }
            else
            {
                direction = (direction + 1) % 4;
                x = x + directions[direction][0];

                y = y + directions[direction][1];
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
