#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string_view>
class IntList
{
private:
    int m_list[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // give this class some initial state for this example

public:
    int &operator[](int index);
    const int &operator[](int index) const;
};

int &IntList::operator[](int index) // for non-const objects: can be used for assignment
{
    return m_list[index];
}

const int &IntList::operator[](int index) const // for const objects: can only be used for access
{
    return m_list[index];
}

struct StudentGrade
{
    std::string name{};
    char grade{};
};
class GradeMap
{
private:
    std::vector<StudentGrade> m_map;
public:
    char &operator[](const std::string & name);
};
char &GradeMap::operator[](const std::string & name)
{
    auto found{std::find_if(m_map.begin(), m_map.end(), [&](const auto &studentGrade) { return studentGrade.name == name; })};
    if (found != m_map.end())
    {
        return found->grade;
    }
    else
    {
        m_map.push_back({name});
        return m_map.back().grade;
    }
}

int main()
{
    IntList list{};
    list[2] = 3; // okay: calls non-const version of operator[]
    std::cout << list[2] << '\n';

    const IntList clist{};
    //clist[2] = 3; // compile error: calls const version of operator[], which returns a const reference.  Cannot assign to this.
    std::cout << clist[2] << '\n';

    std::cout<<"***************************************";

    GradeMap grades{};
 
	grades["Joe"] = 'A';
	grades["Frank"] = 'B';
 
	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

    return 0;
}