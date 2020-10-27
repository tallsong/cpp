/**
 * @file aggregation.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-10-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <functional> // std::reference_wrapper
#include <iostream>
#include <vector>
#include <string>

class Teacher
{
private:
    std::string m_name{};

public:
    /**
     * @brief Construct a new Teacher object
     * 
     * @param name 
     */
    Teacher(const std::string &name)
        : m_name{name}
    {
    }

    const std::string &getName() const { return m_name; }
};
/**
 * @brief 
 * 
 */
class Department
{
private:
    const Teacher &m_teacher; // This dept holds only one teacher for simplicity, but it could hold many teachers
    //std::vector<const Teacher&> m_teachers{}; // Illegal
    std::vector<std::reference_wrapper<const Teacher>> m_teachers{};

public:
    Department(const Teacher &teacher)
        : m_teacher{teacher}
    {
    }
    void add(const Teacher &teacher)
    {
        m_teachers.push_back(teacher);
    }
    friend std::ostream &operator<<(std::ostream &out, const Department &department);
};
std::ostream &operator<<(std::ostream &out, const Department &department)
{
    out << "Department: ";
    for (const auto &teacher : department.m_teachers)
    {
        out << teacher.get().getName() << "  ";
    }
    out << '\n';
    return out;
}
/*



1) std::reference_wrapper lives in the <functional> header.
2) When you create your std::reference_wrapper wrapped object, the object can’t be an anonymous object (since anonymous objects have expression scope would leave the reference dangling).
3) When you want to get your object back out of std::reference_wrapper, you use the get() member function.

*/

/**
 * @brief main fuction
 * 
 * @return int send the program excute result to OS
 */
int main1()
{
    // Create a teacher outside the scope of the Department
    Teacher bob{"Bob"}; // create a teacher

    {
        // Create a department and use the constructor parameter to pass
        // the teacher to it.
        Department department{bob};

    } // department goes out of scope here and is destroyed

    // bob still exists here, but the department doesn't

    std::cout << bob.getName() << " still exists!\n";

    std::string tom{"Tom"};
    std::string berta{"Berta"};

    std::vector<std::reference_wrapper<std::string>> names{tom, berta};

    std::string jim{"Jim"};

    names.push_back(jim);

    for (auto name : names)
    {
        // Use the get() member function to get the referenced string.
        name.get() += " Beam";
    }

    std::cout << jim << '\n'; // Jim Beam

    return 0;
}

int main()
{
    // Create a teacher outside the scope of the Department
    Teacher t1{"Bob"};
    Teacher t2{"Frank"};
    Teacher t3{"Beth"};

    {
        // Create a department and add some Teachers to it
        Department department{t1}; // create an empty Department

        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << department;

    } // department goes out of scope here and is destroyed

    std::cout << t1.getName() << " still exists!\n";
    std::cout << t2.getName() << " still exists!\n";
    std::cout << t3.getName() << " still exists!\n";

    return 0;
}