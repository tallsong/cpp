#include <iostream>
#include <string>
#include <string_view>
 
class Animal
{
protected:
    std::string m_name;
 
    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(const std::string &name)
        : m_name{ name }
    {
    }
 
public:
    const std::string &getName() const { return m_name; }
    virtual std::string_view speak() const { return "???"; }
};
 
class Cat: public Animal
{
public:
    Cat(const std::string &name)
        : Animal{ name }
    {
    }
 
     std::string_view speak() const { return "Meow"; }
};
 
class Dog: public Animal
{
public:
    Dog(const std::string& name)
        : Animal{ name }
    {
    }
 
     std::string_view speak() const { return "Woof"; }
};
 
void report(const Animal &animal)
{
    std::cout << animal.getName() << " says " << animal.speak() << '\n';
}

int main()
{
    Cat cat{"Fred"};
    Dog dog{"Garbo"};

    report(cat);
    report(dog);

    Cat fred{"Fred"};
    Cat misty{"Misty"};
    Cat zeke{"Zeke"};

    Dog garbo{"Garbo"};
    Dog pooky{"Pooky"};
    Dog truffle{"Truffle"};

    // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    Animal *animals[]{&fred, &garbo, &misty, &pooky, &truffle, &zeke};

    for (const auto *animal : animals)
        std::cout << animal->getName() << " says " << animal->speak() << '\n';

    return 0;
}