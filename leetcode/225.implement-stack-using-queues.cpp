/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */
#include<queue>

// @lc code=start
class MyStack
{
private:
    std::queue<int> q;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
        int sz = q.size() - 1;
        for (int i = 0; i < sz; ++i)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int first = q.front();
        q.pop();

        return first;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
