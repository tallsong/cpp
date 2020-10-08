#include <iostream>

class Accumulator
{
private:
    int m_value;

public:
    Accumulator() : m_value{0} {}
    void add(int value) { m_value += value; }

    // Make the reset() function a friend of this class
    friend void reset(Accumulator &accumulator);
};

// reset() is now a friend of the Accumulator class
void reset(Accumulator &accumulator)
{
    // And can access the private data of Accumulator objects
    accumulator.m_value = 0;
}
class Storage2
{
private:
    int m_nValue;
    double m_dValue;

public:
    Storage2(int nValue, double dValue)
    {
        m_nValue = nValue;
        m_dValue = dValue;
    }

    // Make the Display class a friend of Storage
    friend class Display2;
};

class Display2
{
private:
    bool m_displayIntFirst;

public:
    Display2(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }

    void displayItem(const Storage2 &storage)
    {
        if (m_displayIntFirst)
            std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
        else // display double first
            std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
    }
};

class Storage; // forward declaration for class Storage

class Display
{
private:
    bool m_displayIntFirst;

public:
    Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }

    void displayItem(const Storage &storage); // forward declaration above needed for this declaration line
};

class Storage // full definition of Storage class
{
private:
    int m_nValue;
    double m_dValue;

public:
    Storage(int nValue, double dValue)
    {
        m_nValue = nValue;
        m_dValue = dValue;
    }

    // Make the Display::displayItem member function a friend of the Storage class (requires seeing the full declaration of class Display, as above)
    friend void Display::displayItem(const Storage &storage);
};

// Now we can define Display::displayItem, which needs to have seen the full definition of class Storage
void Display::displayItem(const Storage &storage)
{
    if (m_displayIntFirst)
        std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
    else // display double first
        std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
}

class Vector3d;

class Point3d
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{x}, m_y{y}, m_z{z}
    {
    }

    void print() const
    {
        std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
    }

    void moveByVector(const Vector3d &v);
};

class Vector3d
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Vector3d(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{x}, m_y{y}, m_z{z}
    {
    }

    void print() const
    {
        std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
    }

    friend void Point3d::moveByVector(const Vector3d &v); // Point3d is now a friend of class Vector3d
};

void Point3d::moveByVector(const Vector3d &v)
{
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;
}

int main()
{
    Accumulator acc;
    acc.add(5); // add 5 to the accumulator
    reset(acc); // reset the accumulator to 0

    Storage2 storage2(5, 6.7);
    Display2 display2(false);

    display2.displayItem(storage2);

    Storage storage(5, 6.7);
    Display display(false);

    display.displayItem(storage);

    Point3d p{1.0, 2.0, 3.0};
    Vector3d v{2.0, 2.0, -3.0};

    p.print();
    p.moveByVector(v);
    p.print();

    return 0;
}
