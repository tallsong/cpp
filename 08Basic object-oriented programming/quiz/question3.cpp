#include <ctime>   // for time()
#include <cstdlib> // for rand() and srand()
#include <string>
#include <string_view>
#include <iostream>
#include <array>
class Monster
{
public:
    enum class Type
    {
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        max_monster_types,
    };

private:
    Type m_Type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hitPoints{};

public:
    Monster(Type type, const std::string &name, const std::string &roar, int hitPointer)
        : m_Type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPointer}
    {
    }
    std::string_view getTypeString() const
    {
        switch (m_Type)
        {
        case Monster::Type::Dragon:
            return "Dragon";
        case Monster::Type::Goblin:
            return "Goblin";
        case Monster::Type::Ogre:
            return "Ogre";
        case Monster::Type::Orc:
            return "Orc";
        case Monster::Type::Skeleton:
            return "Skeleton";
        case Monster::Type::Troll:
            return "Troll";
        case Monster::Type::Vampire:
            return "Vampire";
        case Monster::Type::Zombie:
            return "Zombie";
        default:
            return "error!";
        }
    }
    void print() const
    {
        std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << "\n";
    }
};

class MonsterGenerator
{
public:
    // Generate a random number between min and max (inclusive)
    // Assumes std::srand() has already been called
    // Assumes max - min <= RAND_MAX
    static int getRandomNumber(int min, int max)
    {
        static constexpr double fraction{1.0 / (static_cast<double>(RAND_MAX) + 1.0)}; // static used for efficiency, so we only calculate this value once
        // evenly distribute the random number across our range
        return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
    }
    static Monster generateMonster()
    {
        auto type{static_cast<Monster::Type>(getRandomNumber(0, static_cast<int>(Monster::Type::max_monster_types) - 1))};
        int hitPoints{getRandomNumber(1, 100)};

        // If your compile is not C++17 capable, use std::array<const char*, 6> instead.
        static constexpr std::array s_names{"Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans"};
        static constexpr std::array s_roars{"*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};

        // Without the cast, compilers with a high warning level complain about
        // an implicit cast from a signed to an unsigned integer.
        auto name{s_names[static_cast<std::size_t>(getRandomNumber(0, s_names.size() - 1))]};
        auto roar{s_roars[static_cast<std::size_t>(getRandomNumber(0, s_roars.size() - 1))]};

        return {type, name, roar, hitPoints};
    }
};

int main()
{
    Monster skeleton{Monster::Type::Skeleton, "Bones", "*rattle*", 4};
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    std::rand();                                               // If using Visual Studio, discard first random value
    Monster m{MonsterGenerator::generateMonster()};
    m.print();
    return 0;
}