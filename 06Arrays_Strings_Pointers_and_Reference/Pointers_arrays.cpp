#include <iostream>
#include<string>
int main1()
{
    int array[5]{9, 7, 5, 3, 1};

    // print address of the array's first element
    std::cout << "Element 0 has address: " << &array[0] << '\n';

    // print the value of the pointer the array decays to
    std::cout << "The array decays to a pointer holding address: " << array << '\n';

    return 0;
}
int main2()
{
    int array[5]{9, 7, 5, 3, 1};

    std::cout << sizeof(array) << '\n'; // will print sizeof(int) * array length

    int *ptr{array};
    std::cout << sizeof(ptr) << '\n'; // will print the size of a pointer

    return 0;
}

void printSize(int *array)
{
    // array is treated as a pointer here
    std::cout << sizeof(array) << '\n'; // prints the size of a pointer, not the size of the array!
}

// C++ will implicitly convert parameter array[] to *array
void printSize2(int array[])
{
    // array is treated as a pointer here, not a fixed array
    std::cout << sizeof(array) << '\n'; // prints the size of a pointer, not the size of the array!
}

int main3()
{
    int array[]{1, 1, 2, 3, 5, 8, 13, 21};
    std::cout << sizeof(array) << '\n'; // will print sizeof(int) * array length

    printSize(array); // the array argument decays into a pointer here

    return 0;
}

int main4()
{
    int value{7};
    int *ptr{&value};

    std::cout << ptr << '\n';
    std::cout << ptr + 1 << '\n';
    std::cout << ptr + 2 << '\n';
    std::cout << ptr + 3 << '\n';
    /*       
    0x7fffffffe0fc
    0x7fffffffe100
    0x7fffffffe104
    0x7fffffffe108
    */
    int array[]{9, 7, 5, 3, 1};

    std::cout << "Element 0 is at address: " << &array[0] << '\n';
    std::cout << "Element 1 is at address: " << &array[1] << '\n';
    std::cout << "Element 2 is at address: " << &array[2] << '\n';
    std::cout << "Element 3 is at address: " << &array[3] << '\n';

    return 0;
}

int *find(int *begin, int *end, int value)
{
    for (int *p{begin}; p != end; ++p)
    {
        if (*p == value)
        {
            return p;
        }
    }

    return end;
}

int main5()
{
    int arr[]{2, 5, 4, 10, 8, 20, 16, 40};

    // Search for the first element with value 20.
    int *found{find(std::begin(arr), std::end(arr), 20)};

    // If an element with value 20 was found, print it.
    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }



    char c{ 'Q' };  //Q�����
    std::cout << &c<<'\n';
    std::string ss{"fdfd"};
    std::cout<<&ss;
    return 0;
}


int main()
{
    std::string{"sdklfjsdlkfjsdlfjlsdjfldks"};
    char c{'q'};
    std::cout<<&c;
    return 0;
}