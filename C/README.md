# Introduction
basical knowledge about C program language

# syntax

```C
typedef unsigned int u32;
typedef struct _PERSON
{
    char name[64];
    int age;
} Person;

void test()
{
    u32 val;       // equal to unsigned int val;
    Person person; // equal struct PERSON person;
}

```
## sizeof

```C
int arr[10];
//arr = NULL; //error, arr is const point here
int *p = arr; 
printf("sizeof(arr):%d\n", sizeof(arr)); // sizeof return length of whole array
printf("&arr type is %s\n", typeid(&arr).name()); //int(*)[10] instead of int*


```



- sizeof return size that allocated for this variable

- A typical memory representation of a C program consists of the following sections.



# memory layout





Each of these six different segments stores different parts of code and have their own read, write permissions. If a program tries to access the value stored in any segment differently than it is supposed to, it results in a `segmentation fault` error.




![memory layout](https://media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg)

![memory layout](https://scaler.com/topics/images/Diagram-for-memory-structure-of-C.webp)


## Text segment  

instruction(code->binary file ->instruction),read only, it's shareable so that a single copy for frequent copy




## Initialized data segment 

Initialized data segment or data segment is part of the computer's virtual memory space of a C program that contains values of all `external`, `global`, `static`, and `constant` variables whose values are initialized at the time of variable declaration in the program.

const comes under data-only area,the remaining types of variables come in the read-write area.
```C
const hello* = "Data segment";
```
Here, the pointer variable `hello` comes under the `read-write` area, and the value of the string literal "`Data segment`" lies comes under initialized `read-only` data segment.


```C
#include<stdio.h>

/* global variables stored in the read-write part of
   initialized data segment
 */
int global_var = 50;
char* hello = "Hello World";
/* global variables stored in the read-only part of
   initialized data segment
 */
const int global_var2 = 30;

int main() {
    // static variable stored in initialized data segment
    static int a = 10; 
    // ...
    return 0;
}

```
Initialized data segment read-write:global_var,hello,a
Initialized data segment read-only:global_var2

## Uninitialized data segment  or bss (b​lock started by symbol)
 Every data in bss is `initialized to arithmetic 0` and `pointers to null pointer` by the kernel before the C program executes. BSS also contains all the `static` and `global` variables, initialized with arithmetic 0. This data segment has `read-write` permissions.
```C
#include <stdio.h>

// Uninitialized global variable stored in the bss segment
int global_variable; 

int main()
{
    // Uninitialized static variable stored in bss
    static int static_variable;
    
    // ..
    printf("global_variable = %d\n", global_variable);
    printf("static_variable = %d\n", static_variable);
    return 0;
}


```

## Stack 
Stack `grows in the direction opposite to heap`. Stack segment `stores the value of local variables and values of parameters passed to a function` along with some additional information like the instruction's return address, which is to be executed after a function call.

## Heap 
Heap is used for memory which is allocated during the run time (dynamically allocated memory). Commands like `malloc`, `calloc`, `free`, `realloc`, etc are used to manage allocations in the heap segment which internally use `sbrk` and `brk` system calls to change memory allocation within the heap segment.


# point
```C
int a[10]; //a is a pointer constant, can't be moidfied
int *b;
```



# memory offset


1. 数组成员对齐规则。第一个数组成员应该放在offset为0的地方，以后每个数组成员应该放在offset为min（当前成员的大小，#pargama pack(n)）整数倍的地方开始（比如int在32位机器为４字节，#pargama pack(2)，那么从2的倍数地方开始存储）。
2. 结构体总的大小，也就是sizeof的结果，必须是min（结构体内部最大成员，#pargama pack(n)）的整数倍，不足要补齐。
3. 结构体做为成员的对齐规则。如果一个结构体B里嵌套另一个结构体A,还是以最大成员类型的大小对齐，但是结构体A的起点为A内部最大成员的整数倍的地方。（struct B里存有struct A，A里有char，int，double等成员，那A应该从8的整数倍开始存储。），结构体A中的成员的对齐规则仍满足原则1、原则2。







```C
struct Teacher
{
	char a;  //8
    long c;  //8
	int b;  //8
}; sizeof : 24


struct Teacher
{
	char a;//  4
	int b;  //4
    long c;  //8
}; sizeof : 16


void test01()
{

	struct Teacher  t1;
	struct Teacher*p = &t1;


	long offsize1 = (long)&(p->b) - (long)p;  //成员b 相对于结构体 Teacher的偏移量
	long offsize2 = offsetof(struct Teacher, b);

	printf("offsize1:%d \n", offsize1); //打印b属性对于首地址的偏移量
	printf("offsize2:%d \n", offsize2);

}


#pragma pack(4)

typedef struct _STUDENT{
	int a;
	char b;
	double c;
	float d;
}Student;

typedef struct _STUDENT2{
	char a;
	Student b; 
	double c;
}Student2;

void test01(){

	//Student
	//a从偏移量0位置开始存储
	//b从4位置开始存储
	//c从8位置开始存储
	//d从12位置开存储
	//所以Student内部对齐之后的大小为20 ，整体对齐，整体为最大类型的整数倍 也就是8的整数倍 为24

	printf("sizeof Student:%d\n",sizeof(Student));

	//Student2 
	//a从偏移量为0位置开始 
	//b从偏移量为Student内部最大成员整数倍开始，也就是8开始
	//c从8的整数倍地方开始,也就是32开始
	//所以结构体Sutdnet2内部对齐之后的大小为：40 ， 由于结构体中最大成员为8，必须为8的整数倍 所以大小为40
	printf("sizeof Student2:%d\n", sizeof(Student2));
}


```



## 手动设置对齐模数


- #pragma pack(show)

显示当前packing alignment的字节数，以warning message的形式被显示。
- pragma pack(push) 

将当前指定的packing alignment数组进行压栈操作，这里的栈是the internal compiler stack,同时设置当前的packing alignment为n；如果n没有指定，则将当前的packing alignment数组压栈。
- #pragma pack(pop) 

从internal compiler stack中删除最顶端的reaord; 如果没有指定n,则当前栈顶record即为新的packing alignement数值；如果指定了n，则n成为新的packing alignment值
- #pragma pack(n)

指定packing的数值，以字节为单位，缺省数值是8，合法的数值分别是1,2,4,8,16。
