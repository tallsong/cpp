#include <iostream>
#include <typeinfo>
#include <cstddef> // for std::nullptr_t

void doSomething(std::nullptr_t ptr)
{
    std::cout << "in doSomething()\n";
}

int main2()
{
    int x{5};
    std::cout << x << '\n';  // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x
    std::cout << *(&x) << '\n';
    std::cout << typeid(&x).name() << '\n'; // prints “pi” (pointer to int)
    //int *iPtr{};

    int value{5};
    int *ptr{&value};           // ptr points to value
    *ptr = 7;                   // *ptr is the same as value, which is assigned 7
    std::cout << value << '\n'; // prints 7
    return 0;
}

void foo(int *&) // We cover & later. Don't worry about it for now, we're only using it to trick the compiler into thinking that p has a value.
{
    // p is a reference to a pointer.  We'll cover references (and references to pointers) later in this chapter.
    // We're using this to trick the compiler into thinking p could be modified, so it won't complain about p being uninitialized.
    // This isn't something you'll ever want to do intentionally.
}

void myNullptr()
{
    int *ptr{nullptr};
}
void print(int x)
{
    std::cout << "print(int): " << x << '\n';
}

void print(int *x)
{
    if (!x)
        std::cout << "print(int*): null\n";
    else
        std::cout << "print(int*): " << *x << '\n';
}

int main3()
{
    int *x{nullptr};
    print(x); // calls print(int*)

    print(nullptr); // calls print(int*) as desired

    return 0;
}

int main()
{
    main2();
    int *p; // Create an uninitialized pointer (that points to garbage)
    foo(p); // Trick compiler into thinking we're going to assign this a valid value

    std::cout << *p << '\n'; // Dereference the garbage pointer

    char *chPtr{};                      // chars are 1 byte
    int *iPtr{};                        // ints are usually 4 bytes
    std::cout << sizeof(chPtr) << '\n'; // prints 4
    std::cout << sizeof(iPtr) << '\n';  // prints 4
    main3();
    return 0;
}
