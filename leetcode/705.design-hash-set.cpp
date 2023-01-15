/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

#include <vector>
#include <list>
class MyHashSet

{
private:
    std::vector<std::list<int>> data;
    static constexpr int base = 777;
    static int hash(int key)
    {
        return key % base;
    }

public:
    MyHashSet() : data(base)
    {
    }

    void add(int key)
    {
        for (auto it{data[hash(key)].begin()}; it != data[hash(key)].end(); ++it)
        {
            if ((*it) == key)
                return;
        }
        data[hash(key)].push_back(key);
    }

    void remove(int key)
    {
        for (auto it{data[hash(key)].begin()}; it != data[hash(key)].end(); ++it)
        {
            if ((*it) == key)
            {
                data[hash(key)].erase(it);
                return;
            }
        }
    }

    bool contains(int key)
    {
        for (auto it{data[hash(key)].begin()}; it != data[hash(key)].end(); ++it)
        {
            if ((*it) == key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

int main()
{

    return 0;
}