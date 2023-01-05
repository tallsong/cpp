#include<string>
#include<iostream>
#include <limits>
int main1()
{
    std::string fullName{};
    //std::cin>>fullName;
    std::getline(std::cin,fullName);
    std::cout<<fullName<<'\n';
    return 0;
}

int main2()
{
	std::cout << "Pick 1 or 2: ";
	int choice{};
	std::cin >> choice;
 
	//std::cin.ignore(32767, '\n'); // ignore up to 32767 characters until a \n is removed
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
 
	std::cout << "Now enter your name: ";
	std::string name{};
	std::getline(std::cin, name);
 
	std::cout << "Hello, " << name << ", you picked " << choice << '\n'<<"\t and the length of your name is "<<name.length();
 
	return 0;
}


int main()
{
  std::string str{ "I saw a red car yesterday." };  
  //               “I saw a blue car yesterday” 
  // ...
  str.replace(8,3,"blue");
  std::cout << str << '\n'; // I saw a blue car yesterday.
  main1();
  main2();
 
  return 0;
}