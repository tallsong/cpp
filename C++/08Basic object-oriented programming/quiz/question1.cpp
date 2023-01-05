#include <iostream>
#include <cmath>
class Point2d
{
private:
    double m_x{};
    double m_y{};

public:
    Point2d(double x = 0.0, double y = 0.0)
        : m_x{x}, m_y{y}
    {
    }
    void print() const
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }

    // double distanceTo(Point2d &other) const
    // {
    //     return std::sqrt((m_x - other.m_x) * (this->m_x - other.m_x) + (m_y - other.m_y) * (this->m_y - other.m_y));
    // }
    friend double distanceFrom(const Point2d &x, const Point2d &y);                                                 
};

double distanceFrom(const Point2d &x,const Point2d &y)
{
    return std::sqrt((x.m_x - y.m_x) * (x.m_x - y.m_x) + (x.m_y - y.m_y) * (x.m_y - y.m_y));
}

int main()
{
    Point2d first{};
    Point2d second{3.0, 4.0};
    first.print();
    second.print();
    //std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}