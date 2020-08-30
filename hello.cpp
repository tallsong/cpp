#include <iostream>
#include <vector>
#include <string>

using namespace std;
void printHello()
{
   std::cout<<"Hello";
}

int main()
{
   vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

   for (const string& word : msg)
   {
      printHello();
      cout << word << " ";
   }
   cout << endl;
}



