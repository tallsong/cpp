/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */
#include <unordered_map>
#include <srand>
#include <ctime>
#include <vector>
// @lc code=start


class RandomizedSet
{
private:
    std::unordered_map<int, int> hashtable;
    std::vector<int> nums;

public:
    RandomizedSet()
    {

        std::srand(unsigned(std::time(nullptr)));
    }

    bool insert(int val)
    {
        if (hashtable.count(val))
            return false;
        hashtable[val] = int(nums.size());
        nums.emplace_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (!hashtable.count(val))
            return false;
        int index = hashtable[val];
        auto last = nums.back();
        nums[index] = last;
        hashtable[last] = index;
        nums.pop_back();
        hashtable.erase(val);

        return true;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

int main()
{

    std::unordered_set<int> set;
    return 0;
}