#include <iostream>
#include <array>
#include <cassert>

class DataTime
{
    int m_year{};
    int m_month{};
    int m_day{};

public:
    void set(const int year, const int month, const int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }
    void print()
    {
        std::cout << "year: " << m_year << "\nmonth: " << m_month << "\nday: " << m_day << '\n';
    }
};

class Point3d
{
    int m_x{};
    int m_y{};
    int m_z{};

public:
    void setValues(const int x, const int y, const int z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }
    void print()
    {
        std::cout << "<" << m_x << " ," << m_y << " ," << m_z << ">\n";
    }
    bool isEqual(const Point3d &p)
    {
        return (p.m_x == m_x && p.m_y == m_y && p.m_z == m_z);
    }
};

class Stack
{
private:
    using container_type = std::array<int, 10>;
    using size_type = container_type::size_type;

    container_type m_array;
    size_type m_next{0};

public:
    void reset()
    {
        m_next = 0;
    }
    bool push(const int x)
    {
        if (m_next !=m_array.size())
        {
            m_array[m_next++] = x;
            return true;
        }
        else
        {
            return false;
        }
    }
    int pop()
    {
        assert(m_next > 0 && "Can not pop empty stack");
        return m_array[--m_next];
    }
    void print()
    {
        std::cout << "( ";
        for (size_type index{0};index<m_next;++index)
        {
            std::cout << m_array[index] << " ";
        }
        std::cout << ")\n";
    }
};








int main()
{
    DataTime datatime{};
    datatime.set(2020, 10, 5);
    datatime.print();

    Point3d p;
    p.setValues(1, 2, 3);
    p.print();

    Stack stack;
    stack.reset();

    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
        stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();


    stack.print();

    return 0;
}