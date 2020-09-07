#include "constants.h"
#include<string>
#include <iostream>

int main1()
{
    std::cout << "Enter a positive number: ";
    int num{};
    std::cin >> num;

    if (num < 0)
    {
        std::cout << "Negative number entered.  Making positive.\n";
        num = -num;
    }

    std::cout << "You entered: " << num;

    return 0;
}



 
int main2()
{
	std::cout << "How many students are in your class? ";
	int students{};
	std::cin >> students;
 
 
	if (students > constants::max_class_size)
		std::cout << "There are too many students in this class";
	else
		std::cout << "This class isn't too large";
 
	return 0;
}


bool passOrFail()
{
    static int counter{0};
    counter++;
    if(counter<=3)
        return true;
    else
    {
        return false;
    }
    
}

int main3()
{
	std::cout << "User #1: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #2: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #3: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #4: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #5: " << (passOrFail() ? "Pass" : "Fail") << '\n';
 
	return 0;
}

int main()
{
    std::cout<<"Enter your full name: ";
    std::string name{};
    std::getline(std::cin,name);
    std::cout<<"Enter your age: ";
    int age;
    std::cin>>age;
    std::cout<<"You've lived "<<static_cast<double>(age)/name.length()<<" years for each letter in your name.";


    return 0;
}