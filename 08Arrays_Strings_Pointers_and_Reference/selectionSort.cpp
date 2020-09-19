#include <algorithm> // for std::swap
#include <iostream>
#include <iterator> // for std::size

void bubbleSort()
{
    int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
    constexpr int length{static_cast<int>(std::size(array))};
    for (int startIndex{0}; startIndex < length - 1; ++startIndex)
    {
        bool isSorted{true};
        for (int currentIndex{0}; currentIndex < length-1-startIndex; ++currentIndex)
        {
            if (array[currentIndex] > array[currentIndex + 1])
            {
                std::swap(array[currentIndex], array[currentIndex + 1]);
                isSorted=false;
            }
                
        }
        if(isSorted)
        {
            std::cout<<"Early termination on iteration "<<startIndex+1<<'\n';
            break;
        }
    }
    for (int index{0}; index < length; ++index)
    {
        std::cout << array[index] << '\t';
    }
    std::cout << '\n';
}

int main()
{
    int array[]{30, 50, 20, 10, 40};
    constexpr int length{static_cast<int>(std::size(array))};
    for (int startIndex{0}; startIndex < length - 1; ++startIndex)
    {
        int largestIndex{startIndex};
        for (int currentIndex{startIndex + 1}; currentIndex < length; ++currentIndex)
        {
            if (array[largestIndex] < array[currentIndex])
            {
                largestIndex = currentIndex;
            }
        }
        std::swap(array[startIndex], array[largestIndex]);
    }
    for (int index{0}; index < length; ++index)
    {
        std::cout << array[index] << '\t';
    }
    std::cout << '\n';
    bubbleSort();
    return 0;
}