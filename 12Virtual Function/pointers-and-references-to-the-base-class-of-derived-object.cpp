#include <array>
#include <string>
#include <string_view>
#include <iostream>
 
class Animal
{
protected:
    std::string m_name{};
    std::string m_speak{};
 
    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view name, std::string_view speak)
        : m_name{ name }, m_speak{ speak }
    {
    }
    
    // To prevent slicing
    Animal(const Animal&) = delete;
    Animal& operator=(const Animal&) = delete;
 
public:
    const std::string& getName() const { return m_name; }
    const std::string& speak() const { return m_speak; }
};
 
class Cat: public Animal
{
public:
    Cat(std::string_view name)
        : Animal{ name, "Meow" }
    {
    }
};
 
class Dog: public Animal
{
public:
    Dog(std::string_view name)
        : Animal{ name, "Woof" }
    {
    }
};
 
int main()
{
    const Cat fred{ "Fred" };
    const Cat misty{ "Misty" };
    const Cat zeke{ "Zeke" };
 
    const Dog garbo{ "Garbo" };
    const Dog pooky{ "Pooky" };
    const Dog truffle{ "Truffle" };
 
    // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    //const auto animals{ std::to_array<const Animal*>({ &fred, &garbo, &misty, &pooky, &truffle, &zeke }) };
    
    // Before C++20, with the array size being explicitly specified
    const std::array<const Animal*, 6> animals{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };
    
    // animal is not a reference, because we're looping over pointers
    for (const auto animal : animals)
    {
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
    }
 
    return 0;
}