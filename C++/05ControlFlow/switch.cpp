#include <iostream>
#include <string>

int calculate(int x, int y, char symbol)
{
    switch (symbol)
    {
    case '+':
        /* code */
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;

    default:
        std::cout << "error! invaild symbool!";
        return 0;
    }
}

enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    ostrich
};
 
std::string getAnimalName(Animal animal)
{
    switch (animal)
    {
        case Animal::chicken:
            return "chicken";
        case Animal::ostrich:
            return "ostrich";
        case Animal::pig:
            return "pig";
        case Animal::goat:
            return "goat";
        case Animal::cat:
            return "cat";
        case Animal::dog:
            return "dog";
 
        default:
            return "???";
    }
}
 
void printNumberOfLegs(Animal animal)
{
    std::cout << "A " << getAnimalName(animal) << " has ";
 
    switch (animal)
    {
        case Animal::chicken:
        case Animal::ostrich:
            // '2' is a single character, so we use single quotes. Don't use full quotes for characters.
            std::cout << '2';
            break;
 
        case Animal::pig:
        case Animal::goat:
        case Animal::cat:
        case Animal::dog:
            std::cout << '4';
            break;
 
        default:
            std::cout << "???";
            break;
    }
 
    std::cout << " legs.\n";
}
int main1()
{
    std::cout << calculate(8, 49, 'g')<<'\n';
    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);
    while (true)
    {
        std::cout<<"fuck \t";
        break;
    }
    
    return 0;
}
int main()
{
    unsigned int count{ 10 };
 
    // count from 10 down to 0
    while (count >= 0)
    {
        if (count == 0)
        {
            std::cout << "blastoff!";
        }
        else
        {
            std::cout << count << ' ';
        }
        --count;
    }
 
    return 0;
}