#include <iostream>
#include<cmath>
#include<vector>
#include<stack>
#include <algorithm>
#include<map>
#include<string>
#include<fstream>
#include<queue>
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


class MyQueue_implementbyqueue {
	stack<int> s1;
	stack<int> s2;
public:
	/** Initialize your data structure here. */
	MyQueue_implementbyqueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		s1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int len = s1.size();
		for (int i = 0; i < len; i++)
		{
			s2.push(s1.top());
			s1.pop();
		}
		int cur = s2.top();
		s2.pop();
		for (int i = 0; i < len - 1; i++)
		{
			s1.push(s2.top());
			s2.pop();
		}
		return cur;
	}

	/** Get the front element. */
	int peek() {
		int len = s1.size();
		for (int i = 0; i < len; i++)
		{
			s2.push(s1.top());
			s1.pop();
		}
		int cur = s2.top();
		for (int i = 0; i < len - 1; i++)
		{
			s1.push(s2.top());
			s2.pop();
		}
		return cur;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return s1.empty() && s2.empty();
	}
};



class MyStack_implementbyqueue
{
	queue<int> a;
public:
	/** Initialize your data structure here. */
	MyStack_implementbyqueue() {
		//nothing to do
	}

	/** Push element x onto stack. */
	void push(int x) {
		a.push(x);
		for (int i = 0; i < a.size() - 1; i++)
		{
			a.push(a.front());
			a.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int n = a.front();
		a.pop();
		return n;
	}

	/** Get the top element. */
	int top() {
		return a.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return a.empty();
	}
};

class MyLinkedList 
{
public:
	/** Initialize your data structure here. */
	struct Node
	{
		int val;
		Node* next;
		Node(int x) :val(x), next(NULL) {}
	};
	int len ;
	Node *head, *tail;
	MyLinkedList()
	{
		len = 0;
		Node* p = new Node(0);
		head = p;
		tail = p;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index<0 || index >= len) return-1;
		Node* p = head;
		for (int i = 0; i < index; i++) p = p->next;
		return p->val;

	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) 
	{
		if (len == 0)
		{
			head->val = val;
		}
		else
		{
			Node* p = new Node(val);
			p->next = head;
			head = p;
		}
		len++;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) 
	{
		if (len == 0)
		{
			tail->val = val;
		}
		else
		{
			Node* p = new Node(val);
			tail->next = p;
			tail = p;
		}
		len++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) 
	{
		if (index > len) return;
		
		if (index <= 0)
		{
			addAtHead(val);

		}
		else
		{
			if (index == len) addAtTail(val);
			else
			{
				Node* p = new Node(val);
				Node* cur = head;
				for (int i = 0; i < index - 1; i++)
				{
					cur = cur->next;
				}
				p->next = cur->next;
				cur->next = p;
				len++;
			}
		}
		

	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) 
	{
		if (index >= 0 && index < len)
		{
			if (index == 0)
			{
				head = head->next;

			}
			else
			{
				Node* p = head;
				for (int i = 0; i < index - 1; i++)
				{
					p = p->next;
				}
				p->next = p->next->next;
				if (index == len - 1)
				{
					tail = p;
				}
			}
			len--;
			
		}
		
	}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */