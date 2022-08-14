#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        auto m{matrix.size()};
        auto n{matrix.at(0).size()};
        vector<int> result(m * n);
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int x{0};
        int y{0};
        int way{0};
        for (int i{0}; i < m * n; ++i)
        {
            result[i] = matrix.at(x).at(y);
            visited[x][y] = 1;
            int next_x{x + directions[way][0]};
            int next_y{y + directions[way][1]};
            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || visited.at(next_x).at(next_y))
                way = (way + 1) % 4;
            x = x + directions[way][0];
            y = y + directions[way][1];
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Solution s;
    vector<int> result = s.spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result.at(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}
