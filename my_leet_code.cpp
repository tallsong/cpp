#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include<queue>
#include<set>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct DoublyListNode
{
	int val;
	DoublyListNode* next, * prev;
	DoublyListNode(int x) : val(x), next(NULL), prev(NULL){}
};
//class Node
//{
//public:
//	int val;
//	Node* prev;
//	Node* next;
//	Node* child;
//
//	Node()
//	{
//	}
//
//	Node(int _val, Node* _prev, Node* _next, Node* _child)
//	{
//		val = _val;
//		prev = _prev;
//		next = _next;
//		child = _child;
//	}
//};



vector<int> twoSum_001(vector<int>& nums, int target)
{
	map<int, int> a;  //建立hash表存放数组元素
	vector<int> b(2, -1);  //存放结果, 声明一个初始大小为2且初始值都为-1的向量
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
vector<int> twoSum2_001(vector<int>& nums, int target) {
	map<int, int> a;  //建立hash表存放数组元素
	vector<int> b(2, -1);  //存放结果, 声明一个初始大小为2且初始值都为-1的向量
	for (int i = 0; i < nums.size(); i++) {
		if (a.count(target - nums[i]) > 0) {
			b[0] = a[target - nums[i]];
			b[1] = i;
			break;
		}
		a[nums[i]] = i;
	}
	return b;
};
int reverse_007(int x) {
	int rev = 0;
	while (x != 0) {
		int pop = x % 10;
		x /= 10;
		if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
		if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
		rev = rev * 10 + pop;
	}
	return rev;
}
bool isPalindrome2_009(int x) {
	int midrev = 0;  //存储后半部分数字的反转结果
	if (x < 0 || (x % 10 == 0 && x != 0))
		return false;  //排除负数和最后一位数字为0的数字
	while (x > midrev) {
		midrev = midrev * 10 + x % 10;
		x /= 10;
	}
	return midrev == x || midrev / 10 == x;  //数字个数为偶数和奇数分两种情况
}
int numIslands_200(vector<vector<char>> & grid)
{
	int h = grid.size();
	if (!h) return 0;
	int w = grid[0].size();
	int num_islands = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (grid[i][j] == '1')
			{
				grid[i][j] = '0';
				num_islands++;
				queue < pair<int, int>> q;
				q.push({ i,j });
				while (!q.empty())
				{
					auto new_center = q.front();
					q.pop();
					int nh = new_center.first;
					int nw = new_center.second;
					if ((nh > 0) && (grid[nh - 1][nw] == '1')) { q.push({ nh - 1,nw }); grid[nh - 1][nw] = '0'; }
					if ((nw > 0) && (grid[nh][nw - 1] == '1')) { q.push({ nh,nw - 1 }); grid[nh][nw - 1] = '0'; }
					if ((nh < h - 1) && (grid[nh + 1][nw] == '1')) { q.push({ nh + 1,nw }); grid[nh + 1][nw] = '0'; }
					if ((nw < w - 1) && (grid[nh][nw + 1] == '1')) { q.push({ nh,nw + 1 }); grid[nh][nw + 1] = '0'; }
				}
			}
		}
	}
	return num_islands;
}


vector<int> plusOne_66(vector<int> & digits) // 加一
{
	int i = digits.size() - 1;
	while (i >= 0 && digits[i] == 9)
		i--;

	for (int j = i + 1; j < digits.size(); j++)
		digits[j] = 0;
	if (i == -1) digits.insert(digits.begin(), 1);
	else digits[i] += 1;
	return digits;
}


vector<int> dailyTemperatures_739(vector<int> & T)
{
	int n = T.size();
	vector<int> result(n);
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j += result[j])
		{
			if (T[j] > T[i])
			{
				result[i] = j - i;
				break;
			}
			else
			{
				if (result[j] == 0)
				{
					result[i] = 0;
					break;
				}
			}
		}
	}
	return result;
}

string decodeString(string s)
{
	int num = 0;
	stack<int> nums;
	string res = "";
	stack<string> strs;
	int len = s.size();
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + s[i] - '0';
		}
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			res = res + s[i];
		}
		if (s[i] == '[')
		{
			nums.push(num);
			num = 0;
			strs.push(res);
			res = "";
		}
		if (s[i] == ']')
		{
			int times = nums.top();
			nums.pop();
			for (int i = 0; i < times; i++)
			{
				strs.top() += res;
			}
			res = strs.top();
			strs.pop();
		}

	}
	return res;
}

vector<vector<int>> floodFill(vector<vector<int>> & image, int sr, int sc, int newColor)
{
	queue<pair<int, int>> q;
	int w = image[0].size();
	int h = image.size();
	q.push({ sr,sc });
	int oldColor = image[sr][sc];
	if (oldColor == newColor) return image;


	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		int nsr = pos.first;
		int nsc = pos.second;
		image[nsr][nsc] = newColor;
		q.pop();
		if (nsc > 0 && image[nsr][nsc - 1] == oldColor) q.push({ nsr,nsc - 1 });
		if (nsc < w - 1 && image[nsr][nsc + 1] == oldColor) q.push({ nsr,nsc + 1 });
		if (nsr > 0 && image[nsr - 1][nsc] == oldColor) q.push({ nsr - 1,nsc });
		if (nsr < h - 1 && image[nsr + 1][nsc] == oldColor) q.push({ nsr + 1,nsc });
	}
	return image;
}

vector<vector<int> > updateMatrix_violence(vector<vector<int> > & matrix)
{
	int rows = matrix.size();
	if (rows == 0)
		return matrix;
	int cols = matrix[0].size();
	vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] == 0)
				dist[i][j] = 0;
			else {
				for (int k = 0; k < rows; k++)
					for (int l = 0; l < cols; l++)
						if (matrix[k][l] == 0) {
							int dist_01 = abs(k - i) + abs(l - j);
							dist[i][j] = min(dist[i][j], abs(k - i) + abs(l - j));
						}
			}
		}
	}
	return dist;

}
vector<vector<int>> updateMatrix_542(vector<vector<int>> & matrix)
{
	int rows = matrix.size();
	if (rows == 0)
		return matrix;
	int cols = matrix[0].size();
	vector<vector<int>> diss(rows, vector<int>(cols, INT_MAX));
	queue<pair<int, int>> q;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] == 0)
			{
				diss[i][j] = 0;
				q.push({ i,j });
			}

		}
	}
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();


		if (cur.first > 0 && diss[cur.first][cur.second] + 1 < diss[cur.first - 1][cur.second])
		{
			diss[cur.first - 1][cur.second] = diss[cur.first][cur.second] + 1;
			q.push({ cur.first - 1,cur.second });
		}
		if (cur.first < rows - 1 && diss[cur.first][cur.second] + 1 < diss[cur.first + 1][cur.second])
		{
			diss[cur.first + 1][cur.second] = diss[cur.first][cur.second] + 1;
			q.push({ cur.first + 1,cur.second });
		}
		if (cur.second > 0 && diss[cur.first][cur.second] + 1 < diss[cur.first][cur.second - 1])
		{
			diss[cur.first][cur.second - 1] = diss[cur.first][cur.second] + 1;
			q.push({ cur.first,cur.second - 1 });
		}
		if (cur.second < cols - 1 && diss[cur.first][cur.second] + 1 < diss[cur.first][cur.second + 1])
		{
			diss[cur.first][cur.second + 1] = diss[cur.first][cur.second] + 1;
			q.push({ cur.first,cur.second + 1 });
		}


	}
	return diss;

}

vector<vector<int> > updateMatrix_dfs(vector<vector<int> > & matrix)
{
	int rows = matrix.size();
	if (rows == 0)
		return matrix;
	int cols = matrix[0].size();
	vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX));
	queue<pair<int, int> > q;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (matrix[i][j] == 0)
			{
				dist[i][j] = 0;
				q.push({ i, j }); //Put all 0s in the queue.
			}

	int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
			if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols)
			{
				if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
					dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
					q.push({ new_r, new_c });
				}
			}
		}
	}
	return dist;
}
bool canVisitAllRooms_841(vector<vector<int>> & rooms)
{
	set<int> visited;
	visited.insert(0);
	queue<int>q;
	q.push(0);
	while (!q.empty())
	{
		int key = q.front();
		q.pop();
		int rc = rooms[key].size();
		for (int i = 0; i < rc; i++)
		{
			if (!visited.count(rooms[key][i]))
			{
				visited.insert(rooms[key][i]);
				q.push(rooms[key][i]);
			}
		}
	}
	return rooms.size() == visited.size();
}

int pivotIndex_724(vector<int> & nums)
{
	int length = nums.size();

	for (int i = 0; i < length; i++)
	{
		int left = 0, right = 0;
		for (int j = 0; j < i; j++)
		{
			left += nums[j];
		}
		for (int k = length - 1; k > i; k--)
		{
			right += nums[k];
		}
		if (left == right) return i;

	}
	return -1;
}

int dominantIndex(vector<int> & nums)
{
	if (nums.size() == 1)
		return 0;
	int small_num = INT_MIN;
	int big_index = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] > nums[big_index])
		{
			small_num = nums[big_index];
			big_index = i;
		}
		else
		{
			if (nums[i] > small_num)
			{
				small_num = nums[i];
			}
		}
	}
	return nums[big_index] >= 2 * small_num ? big_index : -1;
}


vector<int> spiralOrder_54(vector<vector<int>> & matrix)
{
	vector<int> ans;
	if (matrix.size() == 0 || matrix[0].size() == 0)
	{
		return ans;
	}
	int u = 0;
	int r = matrix[0].size() - 1;
	int b = matrix.size() - 1;
	int l = 0;
	while (true)
	{
		for (int i = l; i <= r; i++) ans.push_back(matrix[u][i]);
		if (++u > b) break;
		for (int i = u; i <= b; i++) ans.push_back(matrix[i][r]);
		if (--r < l) break;
		for (int i = r; i >= l; i--) ans.push_back(matrix[b][i]);
		if (--b < u) break;
		for (int i = b; i >= u; i--) ans.push_back(matrix[i][l]);
		if (++l > r) break;
	}
	return ans;

}


vector<vector<int>> generate_118(int numRows)
{
	vector<vector<int>> ans(numRows);
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{

				ans[i].push_back(1);
				//ans[i][j] = 1;
			}
			else
			{
				ans[i].push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
				//ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
			}
		}
	}
	return ans;
}
vector<int> findDiagonalOrder_498(vector<vector<int>> & matrix) //important
{
	vector<int> nums;
	int m = matrix.size();
	if (m == 0) return nums;
	int n = matrix[0].size();
	if (n == 0) return nums;

	bool bXFlag = true;
	for (int i = 0; i < m + n; i++)
	{
		int pm = bXFlag ? m : n;
		int pn = bXFlag ? n : m;

		int x = (i < pm) ? i : pm - 1;
		int y = i - x;

		while (x >= 0 && y < pn)
		{
			nums.push_back(bXFlag ? matrix[x][y] : matrix[y][x]);
			x--;
			y++;
		}

		bXFlag = !bXFlag;
	}
	return nums;
}


string addBinary(string a, string b)
{

	while (a.size() > b.size())
	{
		b = '0' + b;
	}
	while (a.size() < b.size())
	{
		a = '0' + a;
	}
	for (int i = a.size() - 1; i > 0; i--)
	{
		a[i] = a[i] - '0' + b[i];
		if (a[i] > '1')
		{
			a[i] = a[i] - '0' - 2 + '0';
			a[i - 1] = a[i - 1] - '0' + 1 + '0';
		}
	}
	a[0] = a[0] - '0' + b[0];
	if (a[0] > '1')
	{
		a[0] = a[0] - '0' - 2 + '0';
		a = '1' + a;
	}
	return a;
}

int strStr(string haystack, string needle)
{
	if (haystack.size() <= needle.size()) return -1;
	if (needle == "") return 0;
	for (int i = 0; i < haystack.size() - needle.size(); i++)
	{
		if (haystack.substr(i, needle.size()) == needle)
		{
			return i;
		}
	}
	return -1;
}

string longestCommonPrefix(vector<string> & strs)
{
	if (strs.size() == 0) return "";
	if (strs.size() == 1) return strs[0];
	int b = 1;
	string	s = "";
	for (int i = 0; i < strs[0].size(); i++)
	{
		for (int j = 1; j < strs.size(); j++)
		{
			if (strs[j - 1][i] == strs[j][i])
			{
				if (j == strs.size() - 1)
				{
					s = s + strs[0][i];
				}
				else
				{
					continue;
				}
			}
			else
			{
				b = 0;
				break;
			}

		}
		if (b == 0) break;
	}
	return s;
}

void reverseString(vector<char> & s)
{
	int i = 0;
	int j = s.size() - 1;
	while (i < j)
	{
		swap(s[i], s[j]);
		i++;
		j--;
	}
}

int arrayPairSum(vector<int> & nums)
{
	sort(nums.begin(), nums.end());
	int sum = 0;
	for (int i = 0; i < nums.size(); i += 2)
	{
		sum += nums[i];
	}
	return sum;
}

vector<int> twoSum(vector<int> & numbers, int target)
{
	vector<int> ans(2, -1);
	for (int i = 0; i < numbers.size() - 1; i++)
	{
		for (int j = i + 1; j < numbers.size(); j++)
		{
			if (numbers[i] + numbers[j] == target)
			{
				ans[0] = i + 1;
				ans[1] = j + 1;
				return ans;
			}
			if (numbers[i] + numbers[j] > target) break;

		}
	}
	return ans;
}

int removeElement(vector<int> & nums, int val)
{
	int k = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != val)
		{
			nums[k] = nums[i];
			k++;
		}

	}
	return k;
}

int findMaxConsecutiveOnes(vector<int> & nums)
{
	int count = 0;
	int temp = 0;
	for (int i = 0; i < nums.size(); i++)
	{

		if (nums[i] == 1)
		{
			temp += 1;
			if (i == nums.size() - 1)
			{
				count = count > temp ? count : temp;
			}
		}
		else
		{
			count = count > temp ? count : temp;
			temp = 0;
		}
	}
	return count;
}

int minSubArrayLen(int s, vector<int> & nums)
{
	int minLen = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		int count = 0;
		for (int j = i; j < nums.size(); j++)
		{
			count += nums[j];
			if (count >= s)
			{
				if (minLen == 0)
				{
					minLen = j - i + 1;
				}
				else
				{
					minLen = minLen < j - i + 1 ? minLen : j - i + 1;
				}
			}


		}
	}
	return minLen;
}

void rotate(vector<int> & nums, int k)
{
	k = k % nums.size();
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + k);
	reverse(nums.begin() + k, nums.end());

}

vector<int> getRow(int rowIndex) //杨辉三角Ⅱ
{
	vector<int> result;
	for (int i = 0; i <= rowIndex; ++i)
	{
		result.push_back(1);
		for (int j = i - 1; j > 0; --j)
		{
			result[j] += result[j - 1];
		}
	}
	return result;
}

string reverseWords(string s)//********
{
	int start = 0;
	int end = s.size() - 1;
	while (start < s.size() && s[start] == ' ')
	{
		start++;
	}
	while (end >= 0 && s[end] == ' ')
	{
		end++;
	}
	if (start > end) return "";
	for (int i = start; i <= end;)
	{
		while (i <= end && s[i] == ' ') i++;
		int l = i;
		while (l <= end && s[l] != ' ') l++;
		reverse(s.begin() + i, s.begin() + l);
		i = l;
	}

	int tail = start;                                   //处理中间冗余空格
	for (int i = start; i <= end; i++)
	{
		if (s[i] == ' ' && s[i - 1] == ' ') continue;
		s[tail++] = s[i];
	}
	return s.substr(start, tail - start);

}

void moveZeroes_283(vector<int> & nums)
{

	int end_non_zero = 0;
	while (end_non_zero < nums.size() && nums[end_non_zero] == 0) end_non_zero++;
	if (end_non_zero == nums.size()) return;
	for (int i = 0; i < nums.size(); i++)
	{


		if (nums[i] == 0)
		{
			swap(nums[i], nums[end_non_zero]);
		}
		else
		{
			if (i == end_non_zero) end_non_zero++;

		}
		while (end_non_zero < nums.size() && nums[end_non_zero] == 0) end_non_zero++;
		if (end_non_zero == nums.size()) break;
	}

}

bool hasCycle(ListNode * head)
{
	if (head == NULL || head->next == NULL)
	{
		return false;
	}
	ListNode *slow = head;
	ListNode* fast = head->next;
	while (fast)
	{
		slow = slow->next;
		if (fast->next == NULL) return false;
		fast = fast->next->next;
		if (fast == slow) return true;
	}
	return false;
	
}

ListNode* detectCycle_142(ListNode* head)
{
	set<ListNode*> visited;
	ListNode* p = head;
	while (p != NULL)
	{
		if (visited.count(p) == 1)
		{
			return p;
		}
		else
		{
			visited.insert(p);
			p = p->next;
		}
	}
	return NULL;
}


ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
	ListNode* a = headA;
	ListNode* b = headB;
	if (!a || !b)
	{
		return NULL;
	}
	while (a != b)
	{
		if (a)
		{
			a = a->next;
		}
		else
		{
			a = headB;
		}
		if (b)
		{
			b = b->next;
		}
		else
		{
			b = headA;
		}
	}
	return a;
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if (head->next == NULL)
	{
		head = NULL;
		return head;
	}
	else
	{
		if (head->next->next == NULL)
		{
			if (n == 1)
			{
				head->next = NULL;
				return head;
			}
			if (n == 2)
			{
				head = head->next;
				return head;
			}
		}
	}
	ListNode* dummp = new ListNode(0);
	dummp->next = head;
	ListNode* first = dummp;
	ListNode* second = dummp;
	for (int i = 0; i < n; i++)
	{
		first = first->next;
	}
	if (first->next == NULL)
	{
		head = head->next;
		return head;
	}
	else
	{
		while (first->next != NULL)
		{
			first = first->next;
			second = second->next;
		}
	}

	second->next = second->next->next;

	return head;
}



ListNode* reverseList(ListNode* head)
{
	ListNode* p = NULL;
	ListNode* c = head;
	while (c)
	{
		ListNode* t = c->next;
		c->next = p;
		p = c;
		c = t;
	}
	return p;
}




ListNode* removeElements(ListNode* head, int val)
{
	if (head == NULL) return head;
	if (head->next == NULL && head->val == val) return NULL;
	ListNode* p = head;
	while (p->next)
	{
		if (p->next->val == val)
		{
			p->next = p->next->next;
		}
		else
		{
			p = p->next;
		}
	}
	if (head->val == val) head = head->next;

	return head;
}


ListNode* oddEvenList(ListNode* head)
{
	if (head == NULL || head->next == NULL) return head;
	ListNode* odd = head;
	ListNode* even = head->next;
	ListNode* t = even;
	while (even && even->next)
	{
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	even->next = t;
	return head;

}


int maxPoints(vector<vector<int>>& points)//149 直线上最多的点数
{
	if (points.size() < 3) return points.size();
	int Max = 0;
	for (int i = 0; i < points.size(); i++)
	{

		int same = 1;
		for (int j = i + 1; j < points.size(); j++)
		{
			int count = 0;
			if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) same++;
			else
			{
				count++;
				long long x = points[i][0] - points[j][0];
				long long y = points[i][1] - points[j][1];
				for (int k = j + 1; k < points.size(); k++)
				{
					if ((points[i][0] - points[k][0]) * y == (points[i][1] - points[k][1]) * x)
						count++;
				}

			}
			Max = max(Max, count + same);
		}
		if (Max > points.size() / 2) return Max;
	}
	return Max;
}


bool isPalindrome(ListNode* head)
{
	if (head == nullptr || head->next == nullptr) return true;
	int flag = 0;
	ListNode* fast = head, * slow = head;
	stack<int> a;
	while (fast)
	{
		a.push(slow->val);
		slow = slow->next;
		if (fast->next != nullptr)
		{
			fast = fast->next->next;
		}
		else
		{
			fast = nullptr;
			flag = 1;
		}
	}
	if (flag) a.pop();
	while (!a.empty())
	{
		if (a.top() != slow->val) return false;
		a.pop();
		slow = slow->next;
	}
	return true;
}


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	ListNode* head = l1;
	if (l1->val < l2->val)
	{

		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeTwoLists(l2->next, l1);
		return l2;
	}

}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* res = new ListNode(0);
	ListNode* p = res;
	int j = 0;
	while (l1 != NULL || l2 != NULL)
	{
		int c1 = l1 == NULL ? 0 : l1->val;
		int c2 = l2 == NULL ? 0 : l2->val;
		p->next = new ListNode((c1 + c2 + j) % 10);
		j = (c1 + c2 + j) / 10;
		p = p->next;
		l1 = l1 == NULL ? l1 : l1->next;
		l2 = l2 == NULL ? l2 : l2->next;
	}
	if (j != 0) p->next = new ListNode(j);
	return res->next;
}



ListNode* rotateRight_61(ListNode* head, int k)
{
	if (head == NULL || head->next == NULL) return head;
	if (k == 0) return head;
	ListNode* old_tail = head;
	int length = 1;
	while (old_tail->next)
	{
		length += 1;
		old_tail = old_tail->next;
	}
	old_tail->next = head;
	old_tail = head;
	for (int i = 0; i < length-(k % length)-1; i++)  //为什么是 length-(k % length)-1???而不是k？
	{
		old_tail = old_tail->next;
	}
	head = old_tail->next;																																					
	old_tail->next = NULL;
	return head;
}