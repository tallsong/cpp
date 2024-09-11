/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{

    vector<string> result;
    unordered_set<string> cache;
    unordered_set<string> dict;
    string current{""};
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void dfs(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& visited)
    {

        if (!cache.count(current))
            return;
        if (dict.count(current))
        {

            result.push_back(current);
            dict.erase(current);
        }

        for (int i{0}; i < 4; ++i)
        {
            auto new_x = x + directions[i][0];
            auto new_y = y + directions[i][1];
            // 异常检测需要在recursive之前进行，否则会超时
            if (!isInside(board, new_x, new_y))
                continue;
            ;
            if (visited[new_x][new_y])
                continue;
            current.push_back(board[new_x][new_y]);
            visited[new_x][new_y] = true;
            dfs(board, new_x, new_y, visited);
            visited[new_x][new_y] = false;

            current.pop_back();
        }
    }
    bool isInside(vector<vector<char>>& board, int x, int y)
    {
        if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size())
            return true;
        else
            return false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (auto& word : words)
        {
            dict.insert(word);
            for (int i{1}; i <= word.size(); ++i)
            {
                cache.insert(word.substr(0, i));
            }
        }
        for (int x{0}; x < board.size(); ++x)
        {
            for (int y{0}; y < board[0].size(); ++y)
            {
                // 注意，如果便利全部在dfs中会超时， 所以需要这里就开始
                visited[x][y] = true;
                current.push_back(board[x][y]);
                dfs(board, x, y, visited);
                current.pop_back();
                visited[x][y] = false;
            }
        }
        return result;
    }
};
// @lc code=end

int main()
{

    vector<vector<char>> board{{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words{"oath", "pea", "eat", "rain"};
    Solution s;
    for (auto& word : s.findWords(board, words))
    {
        std::cerr << word << '\n';
    }
    return 0;
}
