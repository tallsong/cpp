#include <vector>
#include <iostream>
 
class Point
{
private:
	int m_x{};
	int m_y{};
	int m_z{};
 
public:
	Point(int x, int y, int z)
		: m_x{x}, m_y{y}, m_z{z}
	{
 
	}
 
	friend std::ostream& operator<<(std::ostream &out, const Point &p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ')';
		return out;
	}
};
 
class Shape
{
public:
	virtual std::ostream& print(std::ostream &out) const = 0;
 
	friend std::ostream& operator<<(std::ostream &out, const Shape &p)
	{
		return p.print(out);
	}
	virtual ~Shape() = default;
};
 
class Triangle : public Shape
{
private:
	Point m_p1;
	Point m_p2;
	Point m_p3;
 
public:
	Triangle(const Point &p1, const Point &p2, const Point &p3)
		: m_p1{p1}, m_p2{p2}, m_p3{p3}
	{
	}
 
	virtual std::ostream& print(std::ostream &out) const override
	{
		out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ')';
		return out;
	}
};
 
 
class Circle: public Shape
{
private:
	Point m_center;
	int m_radius{};
 
public:
	Circle(const Point &center, int radius)
		: m_center{center}, m_radius{radius}
	{
	}
	
	virtual std::ostream& print(std::ostream &out) const override
	{
		out << "Circle(" << m_center << ", radius " << m_radius << ')';
		return out;
	}
 
	int getRadius() const { return m_radius;  }
};
 
// h/t to reader Olivier for this updated solution
int getLargestRadius(const std::vector<Shape*> &v)
{
	int largestRadius { 0 };
 
	// Loop through all the shapes in the vector
	for (const auto* element : v) 
	{
		// // Ensure the dynamic cast succeeds by checking for a null pointer result
    		if (auto *c{ dynamic_cast<const Circle*>(element) })
		{
			if (c->getRadius() > largestRadius)
				largestRadius = c->getRadius();
		}
	}
 
    return largestRadius;
}
int main()
{
	std::vector<Shape*> v{
      new Circle{Point{1, 2, 3}, 7},
      new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
      new Circle{Point{4, 5, 6}, 3}
    };
 
	for (const auto* element : v) // element will be a Shape*
		std::cout << *element << '\n';
 
	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';
 
	for (const auto* element : v)
		delete element;
 
	return 0;
}