#include <iostream>
#include <iterator> // for std::size


void maxIndex()
{
    constexpr int scores[]{ 84, 92, 76, 81, 56 };
    constexpr int numStudents{ static_cast<int>(std::size(scores)) };
 
    int maxScore{ 0 }; // keep track of our largest score
    int maxIndex{0};
 
    // now look for a larger score
    for (int student{ 0 }; student < numStudents; ++student)
    {
        if (scores[student] > maxScore)
        {
            maxScore = scores[student];
            maxIndex=student;
        }
    }
 
    std::cout << "The best score was " << maxScore <<" and it have index:"<<maxIndex<< '\n';
 
}


int getNumber()
{
    int number{};
    while (true)
    {
        std::cout << "input a number between 1-9:";
        std::cin >> number;
        if (std::cin.fail())
        {
            std::cin.clear();             // reset any error flags
        }
        std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer
        if(number>=1 && number<=9)
            return number;    
    }
}
int main()
{
    constexpr int array[]{4, 6, 7, 3, 8, 2, 1, 9, 5};
    constexpr int numArray{static_cast<int>(std::size(array))};
    for (int index{0}; index < numArray; ++index)
    {
        std::cout << array[index] << '\t';
    }
    std::cout<<'\n';
    int number{getNumber()};
    for (int index{0}; index < numArray; ++index)
    {
        if(array[index]==number)
        {
            std::cout <<  "The number " << number << " has index " <<  index << "\n";
            break; // since each # in the array is unique, no need to search rest of array
        }
    }
    maxIndex();
    return 0;
}