/*
转换成字符串进行操作
*/
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		long rev;
		if (x < 0) return false;//排除负数
		string str_x = to_string(x);//转换成字符串
		std::reverse(str_x.begin(), str_x.end());//进行反转
		stringstream out(str_x);
		out >> rev;//结果写入rev
		return x == rev;//比较得出结果
	}
};


/*

*/


class Solution {
public:
	bool isPalindrome(int x) {
		int midrev = 0;//存储后半部分数字的反转结果
		if (x < 0 || (x % 10 == 0 && x != 0)) return false;//排除负数和最后一位数字为0的数字
		while (x > midrev)
		{
			midrev = midrev * 10 + x % 10;
			x /= 10;
		}
		return midrev == x || midrev / 10 == x;//数字个数为偶数和奇数分两种情况
	}
};

/*
分析：可以利用栈的特性，将数字的后半部分压入栈内，再一一弹出对比，为此我们需要获取整数的位数，创建一个栈。特别需要注意的是奇数位和偶数位操作的差别。
*/
class Solution {
public:
    int get_length(int x){//获取整数位数
     int leng=0;
     while(x)
        {
            x/=10;
            leng++;
        }
        return leng;
    }
    bool isPalindrome(int x) {
        if(x<0 ||(x%10==0&&x!=0)) return false;
        stack<int> mystack;//创建一个栈
        int l=get_length(x);//存放整数位数
        int p=0;//存放弹出的数据
        if(l%2==0)//偶数位操作
        {
            for(int i=0;i<l/2;i++)
            {
                p=x%10;
                x/=10;
                mystack.push(p);
            }
            for(int j=l/2;j<l;j++)
            {
                p=x%10;
                x/=10;
                if(p==mystack.top())
                {
                    mystack.pop();
                    continue;
                }
                else return false;
            }
            return true;
        }
        else//奇数位操作
        {
            for(int i=0;i<=l/2;i++)
            {
                p=x%10;
                x/=10;
                mystack.push(p);
            }
            mystack.pop();
            for(int j=l/2+1;j<l;j++)
            {
                p=x%10;
                x/=10;
                if(p==mystack.top())
                {
                    mystack.pop();
                    continue;
                }
                else return false;
            }
            return true;
        }
    }
};