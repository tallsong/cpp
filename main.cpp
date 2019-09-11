#include <iostream>
#include<cmath>
#include<vector>
#include<stack>
#include <algorithm>
#include<map>
#include<string>
#include<fstream>
using namespace std;

class MyQueue {
private:
	// store elements
	vector<int> data;
	// a pointer to indicate the start position
	int p_start;
public:
	MyQueue() { p_start = 0; }
	/** Insert an element into the queue. Return true if the operation is successful. */
	bool enQueue(int x) {
		data.push_back(x);
		return true;
	}
	/** Delete an element from the queue. Return true if the operation is successful. */
	bool deQueue() {
		if (isEmpty()) {
			return false;
		}
		p_start++;
		return true;
	};
	/** Get the front item from the queue. */
	int Front() {
		return data[p_start];
	};
	/** Checks whether the queue is empty or not. */
	bool isEmpty()
	{
		return p_start >= data.size();
	}

	int text()
	{
		MyQueue q;
		q.enQueue(5);
		q.enQueue(3);
		if (!q.isEmpty()) {
			cout << q.Front() << endl;
		}
		q.deQueue();
		if (!q.isEmpty()) {
			cout << q.Front() << endl;
		}
		q.deQueue();
		if (!q.isEmpty()) {
			cout << q.Front() << endl;
		}
	}
};
class MyCircularQueue {
private:
	vector<int> data;
	int head;
	int tail;
	int size;
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		data.resize(k);
		head = -1;
		tail = -1;
		size = k;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (isFull()) {
			return false;
		}
		if (isEmpty()) {
			head = 0;
		}
		tail = (tail + 1) % size;
		data[tail] = value;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (isEmpty()) {
			return false;
		}
		if (head == tail) {
			head = -1;
			tail = -1;
			return true;
		}
		head = (head + 1) % size;
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if (isEmpty()) {
			return -1;
		}
		return data[head];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (isEmpty()) {
			return -1;
		}
		return data[tail];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return head == -1;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		return ((tail + 1) % size) == head;
	}
	/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */
};
class MyStack
{
private:
	vector<int> data;               // store elements
public:
	/** Insert an element into the stack. */
	void push(int x) {
		data.push_back(x);
	}
	/** Checks whether the queue is empty or not. */
	bool isEmpty() {
		return data.empty();
	}
	/** Get the top item from the queue. */
	int top() {
		return data.back();
	}
	/** Delete an element from the queue. Return true if the operation is successful. */
	bool pop() {
		if (isEmpty()) {
			return false;
		}
		data.pop_back();
		return true;
	}
};
class MinStack
{
	vector<int> data;
	vector<int> min_data;
public:
	/** initialize your data structure here. */
	MinStack()
	{

	}

	void push(int x) {
		data.push_back(x);
		min_data = data;
	}

	void pop()
	{
		data.pop_back();
		min_data = data;


	}

	int top() {
		return data.back();
	}

	int getMin() {
		reverse(min_data.begin(), min_data.end());
		return min_data.back();
	}
};
vector<int> l001_twoSum(vector<int>& nums, int target) {
	map<int, int> a;//建立hash表存放数组元素
	vector<int> b(2, -1);//存放结果, 声明一个初始大小为2且初始值都为-1的向量
	for (int i = 0; i < nums.size(); i++)
		a.insert(map<int, int>::value_type(nums[i], i));
	for (int i = 0; i < nums.size(); i++)
	{
		if (a.count(target - nums[i]) > 0 && (a[target - nums[i]] != i))
			//判断是否找到目标元素且目标元素不能是本身,count()方法返回值是一个整数，1表示有这个元素，0表示没有这个元素。
		{
			b[0] = i;
			b[1] = a[target - nums[i]];
			break;
		}
	}
	return b;
};
vector<int> l001_twoSum2(vector<int>& nums, int target) {
	map<int, int> a;//建立hash表存放数组元素
	vector<int> b(2, -1);//存放结果, 声明一个初始大小为2且初始值都为-1的向量
	for (int i = 0; i < nums.size(); i++)
	{
		if (a.count(target - nums[i]) > 0)
		{
			b[0] = a[target - nums[i]];
			b[1] = i;
			break;
		}
		a[nums[i]] = i;
	}
	return b;
};
int l007_reverse(int x)
{
	int rev = 0;
	while (x != 0)
	{
		int pop = x % 10;
		x /= 10;
		if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
		if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
		rev = rev * 10 + pop;
	}
	return rev;
}
bool l009_isPalindrome2(int x) {
	int midrev = 0;//存储后半部分数字的反转结果
	if (x < 0 || (x % 10 == 0 && x != 0)) return false;//排除负数和最后一位数字为0的数字
	while (x > midrev)
	{
		midrev = midrev * 10 + x % 10;
		x /= 10;
	}
	return midrev == x || midrev / 10 == x;//数字个数为偶数和奇数分两种情况
}
vector<int> l739_dailyTemperatures(vector<int>& T)
{
	stack<int> s;
	int n = T.size();
	vector<int> res(n);
	for (int i = n - 1; i >= 0; --i) {
		while (!s.empty() && T[i] >= T[s.top()])
		{
			s.pop();
		}
		res[i] = s.empty() ? 0 : s.top() - i;
		s.push(i);
	}
	return res;
}
int main()
{
	// 1. Initialize a stack.
	stack<int> s;
	// 2. Push new element.
	s.push(5);
	s.push(13);
	s.push(8);
	s.push(6);
	// 3. Check if stack is empty.
	if (s.empty()) {
		cout << "Stack is empty!" << endl;
		return 0;
	}
	// 4. Pop an element.
	s.pop();
	// 5. Get the top element.
	cout << "The top element is: " << s.top() << endl;
	// 6. Get the size of the stack.
	cout << "The size is: " << s.size() << endl;
}