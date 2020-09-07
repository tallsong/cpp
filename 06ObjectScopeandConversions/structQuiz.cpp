#include <iostream>
#include <string>
struct Advertising
{
    int adsShown;
    double clickThroughRatePercentage;
    double averageEarningsPerClick;
};
Advertising getAdvertising()
{
    Advertising temp;
    std::cout << "How many ads were shown today? ";
    std::cin >> temp.adsShown;
    std::cout << "What percentage of ads were clicked on by users? ";
    std::cin >> temp.clickThroughRatePercentage;
    std::cout << "What was the average earnings per click? ";
    std::cin >> temp.averageEarningsPerClick;
    return temp;
}

void printAdvertising(Advertising ad)
{
    std::cout << "Number of ads shown: " << ad.adsShown << '\n';
    std::cout << "Click through rate: " << ad.clickThroughRatePercentage << '\n';
    std::cout << "Average earnings per click: $" << ad.averageEarningsPerClick << '\n';

    // The following line is split up to reduce the length
    // We need to divide ad.clickThroughRatePercentage by 100 because it's a percent of 100, not a multiplier
    std::cout << "Total Earnings: $" << (ad.adsShown * ad.clickThroughRatePercentage / 100 * ad.averageEarningsPerClick) << '\n';
}
struct Fraction
{
    int numerator;
    int denominator;
};
Fraction getFraction()
{
    Fraction temp;
    std::cout << "Enter a numerator ";
    std::cin >> temp.numerator;
    std::cout << "Enter a denominator ";
    std::cin >> temp.denominator;
    return temp;
}

double multiply(Fraction fraction1, Fraction fraction2)
{
    return static_cast<double>(fraction1.numerator * fraction2.numerator) / (fraction2.denominator * fraction1.denominator);
}
enum class MonsterType
{
    ogre,
    dragon,
    orc,
    spider,
    slime,
};
struct Monster
{
    MonsterType type;
    std::string name;
    int health;
};
void printMonster(Monster monster)
{
     std::cout << "This "<< static_cast<int>(monster.type) <<" is named "<<monster.name<<" and has "<<monster.health<<" health.\n";
}
int main1()
{
    Fraction fraction1{getFraction()};
    Fraction fraction2{getFraction()};
    std::cout << multiply(fraction1, fraction2);
    return 0;
}

int main()
{
    Monster monster1{MonsterType::ogre, "Trog", 145};
    Monster monster2{MonsterType::slime, "Blrp", 23};
    printMonster(monster1);
    printMonster(monster2);
    return 0;
}