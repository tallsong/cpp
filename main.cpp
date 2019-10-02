#include <iostream>
#include<cmath>
#include<vector>
#include<stack>
#include <algorithm>
#include<map>
#include<string>
#include<fstream>
#include<queue>
#include<set>
#include<climits>
using namespace std;






int main()
{
	int nums[6] = { -1,-1,0,1,1,0 };
	vector<int> n(nums, *(&nums + 1));
	cout <<INT_MAX<<endl<<INT_MIN;
}


//int main() {
//	// 1. initialize
//	vector<int> v0;
//	vector<int> v1(5, 0);
//	// 2. make a copy
//	vector<int> v2(v1.begin(), v1.end());
//	vector<int> v3(v2);
//	// 2. cast an array to a vector
//	int a[5] = { 0, 1, 2, 3, 4 };
//	vector<int> v4(a, *(&a + 1));
//	// 3. get length
//	cout << "The size of v4 is: " << v4.size() << endl;
//	// 4. access element
//	cout << "The first element in v4 is: " << v4[0] << endl;
//	// 5. iterate the vector
//	cout << "[Version 1] The contents of v4 are:";
//	for (int i = 0; i < v4.size(); ++i) {
//		cout << " " << v4[i];
//	}
//	cout << endl;
//	cout << "[Version 2] The contents of v4 are:";
//	for (int& item : v4) {
//		cout << " " << item;
//	}
//	cout << endl;
//	cout << "[Version 3] The contents of v4 are:";
//	for (auto item = v4.begin(); item != v4.end(); ++item) {
//		cout << " " << *item<< typeid(*item).name();
//
//	}
//	cout << endl;
//	// 6. modify element
//	v4[0] = 5;
//	// 7. sort
//	sort(v4.begin(), v4.end());
//	// 8. add new element at the end of the vector
//	v4.push_back(-1);
//	// 9. delete the last element
//	v4.pop_back();
//}

//int main() {
//	// 1. Initialize
//	int a0[5];
//	int a1[5] = { 1, 2, 3 };  // other element will be set as the default value
//	// 2. Get Length
//	int size = sizeof(a1) / sizeof(*a1);
//	cout << "The size of a1 is: " << size << endl;
//	// 3. Access Element
//	cout << "The first element is: " << a1[0] << endl;
//	// 4. Iterate all Elements
//	cout << "[Version 1] The contents of a1 are:";
//	for (int i = 0; i < size; ++i) {
//		cout << " " << a1[i];
//	}
//	cout << endl;
//	cout << "[Version 2] The contents of a1 are:";
//	for (int& item : a1) {
//		cout << " " << item;
//	}
//	cout << endl;
//	// 5. Modify Element
//	a1[0] = 4;
//	// 6. Sort
//	sort(a1, a1 + size);
//}



//int main()
//{
//	vector<vector<int>> obj(3,vector<int>(3,0));//默认值为0,默认size为0
//	obj[1][1] = 1;
//	for (unsigned int i  = 0; i < obj.size(); i++)//size()容器中实际数据个数 
//	{
//		cout << obj.size() << ","<<endl;
//	}
//	auto a = '11' ;
//	cout << typeid('1'-'0').name()<<endl;
//	cout << typeid('1' - '0').name();
//	cout << __cplusplus << endl;
//
//	cout << 1;
//	return 0;
//
//}