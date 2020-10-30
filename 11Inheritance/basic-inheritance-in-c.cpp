#include <iostream>
#include <string>
 
class Person
{
public:
    std::string m_name{};
    int m_age{};
 
    Person(const std::string& name = "", int age = 0)
        : m_name{name}, m_age{age}
    {
    }
 
    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }
 
};
 
// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
public:
    double m_battingAverage{};
    int m_homeRuns{};
 
    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
       : m_battingAverage{battingAverage}, m_homeRuns{homeRuns}
    {
    }
};
 
int main()
{
    // Create a new BaseballPlayer object
    BaseballPlayer joe{};
    // Assign it a name (we can do this directly because m_name is public)
    joe.m_name = "Joe";
    // Print out the name
    std::cout << joe.getName() << '\n'; // use the getName() function we've acquired from the Person base class
 
    return 0;
}