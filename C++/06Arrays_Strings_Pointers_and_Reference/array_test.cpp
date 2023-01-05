#include <iostream>

namespace Animal
{
    enum Animal
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        nake,
        max_animals
    };
}

int main()
{

    double temperature[365]{};

    int legs[Animal::max_animals]{2, 4, 2, 4, 2, 0};
    std::cout << "elephant has " << legs[Animal::elephant] << " legs\n"
              << temperature[0];
    return 0;
}