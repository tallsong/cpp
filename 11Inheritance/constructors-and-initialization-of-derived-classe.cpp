#include <iostream>
#include <string>

class Person
{
private:
    std::string m_name;
    int m_age;

public:
    Person(const std::string &name = "", int age = 0)
        : m_name{name}, m_age{age}
    {
    }

    const std::string &getName() const { return m_name; }
    int getAge() const { return m_age; }
};
// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
private:
    double m_battingAverage;
    int m_homeRuns;

public:
    BaseballPlayer(const std::string &name = "", int age = 0,
                   double battingAverage = 0.0, int homeRuns = 0)
        : Person{name, age}, // call Person(const std::string&, int) to initialize these fields
          m_battingAverage{battingAverage}, m_homeRuns{homeRuns}
    {
    }

    double getBattingAverage() const { return m_battingAverage; }
    int getHomeRuns() const { return m_homeRuns; }
};
class Base
{
private: // our member is now private
    int m_id;

public:
    Base(int id = 0)
        : m_id{id}
    {
    }

    int getId() const { return m_id; }
};

class Derived : public Base
{
private: // our member is now private
    double m_cost;

public:
    Derived(double cost = 0.0, int id = 0)
        : Base{id}, // Call Base(int) constructor with value id!
          m_cost{cost}
    {
    }

    double getCost() const { return m_cost; }
};

class Fruit
{
private:
    std::string m_name;
    std::string m_color;

public:
    Fruit(const std::string &name, const std::string color)
        : m_name{name}, m_color{color}
    {
    }
    const std::string &getName() const
    {
        return m_name;
    }
    const std::string &getColor() const
    {
        return m_color;
    }
};
class Apple : public Fruit
{
    double m_fiber;

public:
    Apple(const std::string &name, const std::string & color, double fiber)
        : Fruit(name, color), m_fiber{fiber}
    {
    }
    double getFiber() const
    {
        return m_fiber;
    }
   
};
std::ostream &operator<<(std::ostream &out, const Apple &apple)
{
    out << "Apple("<<apple.getName()<<", "<<apple.getColor()<<", "<<apple.getFiber()<<")";
    return out;
}
class Banana : public Fruit
{
public:
    Banana(const std::string &name, const std::string color)
        : Fruit(name, color)
    {
    }
};
std::ostream &operator<<(std::ostream &out, const Banana &banana)
{
    out << "Banana("<<banana.getName()<<", "<<banana.getColor()<<")";
    return out;
}
int main()
{
    Derived derived{1.3, 5}; // use Derived(double, int) constructor
    std::cout << "Id: " << derived.getId() << '\n';
    std::cout << "Cost: " << derived.getCost() << '\n';

    BaseballPlayer pedro{"Pedro Cerrano", 32, 0.342, 42};

    std::cout << pedro.getName() << '\n';
    std::cout << pedro.getAge() << '\n';
    std::cout << pedro.getHomeRuns() << '\n';

    const Apple a{"Red delicious", "red", 4.2};
    std::cout << a << '\n';

    const Banana b{"Cavendish", "yellow"};
    std::cout << b << '\n';
    return 0;
}