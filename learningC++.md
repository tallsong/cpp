# P71
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
int emus{7};//set emus to 7
int emus = {7};//set emus to 7
int emus = {};//set emus to 0
int emus{};//set emus to 0

cout<<hex ; 修改cout显示证书的方式;