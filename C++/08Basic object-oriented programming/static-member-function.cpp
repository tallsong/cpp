#include <iostream>
#include <vector>
class Something
{
private:
    static int s_value;

public:
    static int getValue() { return s_value; } // static member function
};

int Something::s_value{1}; // initializer
class IDGenerator
{
private:
    static int s_nextID; // Here's the declaration for a static member

public:
    static int getNextID(); // Here's the declaration for a static function
};

// Here's the definition of the static member outside the class.  Note we don't use the static keyword here.
// We'll start generating IDs at 1
int IDGenerator::s_nextID{1};

// Here's the definition of the static function outside of the class.  Note we don't use the static keyword here.
int IDGenerator::getNextID() { return s_nextID++; }

class MyClass
{
public:
    static std::vector<char> s_mychars;
};

std::vector<char> MyClass::s_mychars{
    [] { // The parameter list of lambdas without parameters can be omitted.
        // Inside the lambda we can declare another vector and use a loop.
        std::vector<char> v{};

        for (char ch{'a'}; ch <= 'z'; ++ch)
        {
            v.push_back(ch);
        }

        return v;
    }() // Call the lambda right away
};
int main()
{
    std::cout << Something::getValue() << '\n';
    for (int count{0}; count < 5; ++count)
        std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';

    return 0;
}
