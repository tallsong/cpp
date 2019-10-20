# my_cpp
sqe8ql
this is leetcode solution and learn cpp for you all

***[markdown basic-syntax](https://www.markdownguide.org/basic-syntax/)***

# P94
答案:P950
# 基础知识 
## C++ 与C的区别
C++中函数的形参的列表为void表面函数不接受任何参数，这与括号里面空着等效；
C中函数的形参的列表为void表面函数不接受任何参数，让括号里面空着意外着对是否接受参数保存沉默；
# 处理数据
## 简单变量
计算机内存的基本单位是位（bit），可以看作电子开关，可以开也可以关；

字节（bytes）通常指的是8位的内存单元;

sizeof(short):2    (bytes )	sizeof(int):4 	sizeof(long):4	sizeof(long):8

大括号初始化：

- int emus{7};//set emus to 7

- int emus = {7};//set emus to 7

- int emus = {};//set emus to 0

- int emus{};//set emus to 0

对象是指一块能存储数据并具有某种类型的内存空间

指针p也是对象，它同样有地址&p和存储的值p，只不过，p存储的数据类型是数据的地址。

cout<<hex ; 修改cout显示证书的方式;

'9' - '0'的类型为**int**

# 指针

* 箭头（->）：左边必须为指针；
* 点号（.）：左边必须为实体。
*  
## Array
```C++
int a1[5] = { 1, 2, 3 };  // other element will be set as the default value，也就是该数组的第4，5个元素的值为0
int size = sizeof(a1) / sizeof(*a1);  // sizeof(a1)的值为20，sizeof(*a1)为4，*a1为数组第一个元素，值为1，*(a1+2)为数组第三个元素，值为3
for (int& item : a1) {cout << " " << item;} // Iterate all Elements
sort(a1, a1 + size); //sort
```
## vector
```C++
	vector<int> v2(v1.begin(), v1.end());vector<int> v3(v2);// 2. make a copy
	// 2. cast an array to a vector
	int a[5] = { 0, 1, 2, 3, 4 };
	vector<int> v4(a, *(&a + 1));  //如果v4.rezise(3)，会把后面的两个值丢掉，此时的值为0,1,2
	// 5. iterate the vector
	cout << "[Version 1] The contents of v4 are:";
	for (int i = 0; i < v4.size(); ++i) {
		cout << " " << v4[i];
	}
	cout << endl;
	cout << "[Version 2] The contents of v4 are:";
	for (int& item : v4) {
		cout << " " << item;
	}
	cout << endl;
	cout << "[Version 3] The contents of v4 are:";
	for (auto item = v4.begin(); item != v4.end(); ++item) {
		cout << " " << *item;//typeid(*item).name()的值为int

	}
```


