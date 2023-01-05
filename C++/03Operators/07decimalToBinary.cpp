#include <iostream>
#include <cmath>
int getInput()
{
    std::cout << "Enter a Integer between 0 and 255: ";
    int x{};
    std::cin >> x;
    return x;
}
bool isGreatPowerOf2(int x, int y)
{
    if (x >= pow(2, y))
        return true;
}
int main()
{
    int x{getInput()};
    for (int i = 7; i >= 0; i--)
    {
        if (isGreatPowerOf2(x, i))
        {
            std::cout << 1;
            x -= pow(2, i);
        }
        else
        {
            std::cout << 0;
        }
        if (i == 4)
            std::cout << '\t';
    }
    std::cout << '\n';
    return 0;
}