#include <iostream>
 
// tempPtr is now a reference to a pointer, so any changes made to tempPtr will change the argument as well!
void setToNull(int *&tempPtr)
{
    tempPtr = nullptr; // use 0 instead if not C++11
}
 
int main()
{ 
    // First we set ptr to the address of five, which means *ptr = 5
    int five{ 5 };
    int *ptr{ &five };
	
    // This will print 5
    std::cout << *ptr;
 
    // tempPtr is set as a reference to ptr
    setToNull(ptr);
 
    // ptr has now been changed to nullptr!
 
    if (ptr)
        std::cout << *ptr;
    else
        std::cout << " ptr is null";
 
    return 0;
}