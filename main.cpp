#include <iostream>
#include<cmath>
#include<vector>
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
	bool isEmpty() {
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
int main()
{
	cout << "hello world";
	return 0;
}