//11.25 T16
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
#include<math.h>
#include<fstream>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include<cstdio>
#include<stdio.h>
using namespace std;
int fuck()
{
	ofstream outfile;
	outfile.open("exam.cpp");
	cout << outfile.precision(4);
	int k = 5;
	while (--k > 0)
	{
		cout << "fuck!";
	}
	return 0;
}
enum gender{man,ferman};
struct student
{
	long no, birthday;
	char name[22];
	gender sex;
	float score;
};
union student2
{
	long no, birthday;
	char name[22];
	gender sex;
	float score;
};
template <class T1,class T2>
T1 add(T1 x, T2 y)
{
	cout << "(" << sizeof(T1) << "," << sizeof(T2) << ")\t";
	return x + y;
}

//template<class TNO,class TScore,int num>
//class Student
//{
//private:
//	int n;
//	TNO StudentId[num];
//	TScore score[num];
//public:
//	void append(TNO ID, TScore s);
//	void Delete(TNO ID);
//	int search(TND ID);
//	void sort();
//	void DispAll();
//	Student();
//
//};


int main2()
{

	//make_heap(firs, last, comp);
	int a[5] = { 1,2,3,4,5 };
	cout << *a;
	return 0;
}




const int N = 1010, INF = 1e9;

int n, m;
int f[N][N];        //  f[i][j]表示共i层楼j个鸡蛋时最少要试几次保证能找到临界点

int main3()
{
	//scanf_s("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		//  楼层数为i时，鸡蛋数量为1时，需要从低到高遍历，共i次
		f[i][1] = i;

		for (int j = 2; j <= m; j++)
		{
			//  要求最小值时，先反向赋一个很大的值
			f[i][j] = INF;

			//  遍历鸡蛋扔在的k层的情况
			for (int k = 1; k <= i; k++)
				/*
					设临界值为t
					f[k - 1][j - 1]为鸡蛋碎了，t在[1, k]这个区间中，共k层，剩余j - 1个鸡蛋
					f[i - k][j]为鸡蛋未碎，t在[k + 1, i]这个区间中，共i - k层，剩余j个鸡蛋
					在两种情况中取较大值（考虑最坏情况）加上本次，更新f[i][j]
				*/
				f[i][j] = min(f[i][j], max(f[k - 1][j - 1], f[i - k][j]) + 1);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%6d", f[i][j]);
		puts("");
	}
	main2();
	return 0;
}


void main4()
{
	typedef char* pStr;
	char string[4] = "abc";
	 const char* p1 = string;
	 const pStr p2 = string;
	 p1++;
	 int id[sizeof(unsigned long)];
}

int main()
{
	char a = 'a';
	cout <<static_cast<void*>(&a);
}