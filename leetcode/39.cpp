#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{

    vector<vector<int>> result;

    vector<int> current;

    int current_sum{0};

    void helper(int start, int target, vector<int>& candidates)
    {

        if (current_sum == target)
        {
            result.push_back(current);
        }
        if (current_sum > target)
            return;

        for (int index{start}; index < candidates.size(); ++index)
        {

            current.push_back(candidates[index]);
            current_sum += candidates[index];
            // index不加一传入表明元素可以重复
            helper(index, target, candidates);
            current_sum -= candidates[index];
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {

        helper(0, target, candidates);
        return result;
    }
};

int main()
{
    Solution solution;
    std::vector<int> can{2, 3, 6, 7};
    for (auto& vecs : solution.combinationSum(can, 7))
    {
        for (auto num : vecs)
        {
            std::cerr << num;
        }
        std::cerr << '\n';
    }
    return 0;
}