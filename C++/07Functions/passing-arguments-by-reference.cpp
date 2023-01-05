#include <iostream>
 
// Note: You need to specify the array size in the function declaration
void printElements(int (&arr)[4])
{
  int length{ sizeof(arr) / sizeof(arr[0]) }; // we can now do this since the array won't decay
  
  for (int i{ 0 }; i < length; ++i)
  {
    std::cout << arr[i] << std::endl;
  }
}
 
int main()
{
    int arr[]{ 99, 20, 14, 80 };
    
    printElements(arr);
 
    return 0;
}