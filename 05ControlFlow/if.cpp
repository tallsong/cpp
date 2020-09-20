#include <iostream>
#include <string>
 
int main()
{
    std::string firstName{};
    std::string lastName{};
 
    std::cout << "First name: ";
    std::cin >> firstName;
 
    std::cout << "Last name: ";
    std::cin >> lastName;
 
    if (std::string fullName{ firstName + ' ' + lastName }; fullName.length() > 20)  //C++ 17
    {
        std::cout << '"' << fullName << "\"is too long!\n";
    }
    else
    {
        std::cout << "Your name is " << fullName << '\n';
    }
 
    // code that doesn't need @fullName
 
    return 0;
}