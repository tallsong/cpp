# Fundamental Data Types
## Now that fixed-width integers have been added to C++, the best practice for integers in C++ is as follows:
- int should be preferred when the size of the integer doesn’t matter (e.g. the number will always fit within the range of a 2 byte signed integer). For example, if you’re asking the user to enter their age, or counting from 1 to 10, it doesn’t matter whether int is 16 or 32 bits (the numbers will fit either way). This will cover the vast majority of the cases you’re likely to run across.
- If you need a variable guaranteed to be a particular size and want to favor performance, use std::int_fast#_t.
- If you need a variable guaranteed to be a particular size and want to favor memory conservation over performance, use std::int_least#_t. This is used most often when allocating lots of variables.
------------------
## Floating point number
- Favor double over float unless space is at a premium, as the lack of precision in a float will often lead to inaccuracies.
## const
- Any variable that should not be modifiable after initialization and whose initializer is known at compile-time should be declared as constexpr.
- Any variable that should not be modifiable after initialization and whose initializer is not known at compile-time should be declared as const.
# Debug
- When using print statements, use std::cerr instead of `std::cout`.

## literals

| Data Type | Suffix                                    | Meaning            |
| --------- | ----------------------------------------- | ------------------ |
| int       | u or U                                    | unsigned int       |
| int       | l or L                                    | long               |
| int       | ul, uL, Ul, UL, lu, lU, Lu, or LU         | unsigned long      |
| int       | ll or LL                                  | long long          |
| int       | ull, uLL, Ull, ULL, llu, llU, LLu, or LLU | unsigned long long |
| double    | f or F                                    | float              |
| double    | l or L                                    | long double        |

# Operators
- [Table of operators](https://www.learncpp.com/cpp-tutorial/operator-precedence-and-associativity/)
- [scope-duration-and-linkage-summary](https://www.learncpp.com/cpp-tutorial/scope-duration-and-linkage-summary/)
- The modulus operator can also work with negative operands. x % y always returns results with the sign of x.
- Avoid the postfix versions of these operators whenever possible.
- `double x{ 0.1 + 0.1 + 0.1 }; return (x == 0.3);` return false;
- De Morgan’s law says that if we distribute a NOT, we need to flip ORs and ANDs to the other. So ~(option4 | option5) becomes ~option4 & ~option5.
-  In C++, the term inline has evolved to mean “multiple definitions are allowed”.
- When applied to a global variable, the static keyword defines the global variable as having internal linkage, meaning the variable cannot be exported to other files.
- When applied to a local variable, the static keyword defines the local variable as having static duration, meaning the variable will only be created once, and will not be destroyed until the end of the program.
- int8_t is actually a type alias for signed char
- Don’t assign the same value to two enumerators in the same enumeration unless there’s a very good reason.
# Arrays, Strings, Pointers, and References
## Pointers
- When declaring a pointer variable, put the asterisk next to the variable name.
- When declaring a function, put the asterisk of a pointer return value next to the type.
## poinnter and array
- Favor the pointer syntax (*) over the array syntax ([]) for array function parameters.
-  array[n] is the same as *(array + n)
- Pass non-pointer, non-fundamental data type variables (such as structs) by (const) reference, unless you know that passing it by value is faster.
- An array that decayed to a pointer cannot be used in a for-each loop.
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


