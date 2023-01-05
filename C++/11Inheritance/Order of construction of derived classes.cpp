#include <iostream>
 
class Base
{
public:
    int m_id;
 
    Base(int id=0)
        : m_id(id)
    {
        std::cout << "Base\n";
    }
 
    int getId() const { return m_id; }
};
 
class Derived: public Base
{
public:
    double m_cost;
 
    Derived(double cost=0.0)
        : m_cost(cost)
    {
        std::cout << "Derived\n";
    }
 
    double getCost() const { return m_cost; }
};
 
int main()
{
    std::cout << "Instantiating Base\n";
    Base cBase;
 
    std::cout << "Instantiating Derived\n";
    Derived cDerived;
 
    return 0;
}
/*
class Base
{
public:
    int m_public;
protected:
    int m_protected;
private:
    int m_private;
};
 
class Pub: public Base // note: public inheritance
{
    // Public inheritance means:
    // Public inherited members stay public (so m_public is treated as public)
    // Protected inherited members stay protected (so m_protected is treated as protected)
    // Private inherited members stay inaccessible (so m_private is inaccessible)
public:
    Pub()
    {
        m_public = 1; // okay: m_public was inherited as public
        m_protected = 2; // okay: m_protected was inherited as protected
        m_private = 3; // not okay: m_private is inaccessible from derived class
    }
};
 
int main()
{
    // Outside access uses the access specifiers of the class being accessed.
    Base base;
    base.m_public = 1; // okay: m_public is public in Base
    base.m_protected = 2; // not okay: m_protected is protected in Base
    base.m_private = 3; // not okay: m_private is private in Base
 
    Pub pub;
    pub.m_public = 1; // okay: m_public is public in Pub
    pub.m_protected = 2; // not okay: m_protected is protected in Pub
    pub.m_private = 3; // not okay: m_private is inaccessible in Pub

*/


/*
class Base
{
public:
    int m_public;
protected:
    int m_protected;
private:
    int m_private;
};
 
class Pri: private Base // note: private inheritance
{
    // Private inheritance means:
    // Public inherited members become private (so m_public is treated as private)
    // Protected inherited members become private (so m_protected is treated as private)
    // Private inherited members stay inaccessible (so m_private is inaccessible)
public:
    Pri()
    {
        m_public = 1; // okay: m_public is now private in Pri
        m_protected = 2; // okay: m_protected is now private in Pri
        m_private = 3; // not okay: derived classes can't access private members in the base class
    }
};
 
int main()
{
    // Outside access uses the access specifiers of the class being accessed.
    // In this case, the access specifiers of base.
    Base base;
    base.m_public = 1; // okay: m_public is public in Base
    base.m_protected = 2; // not okay: m_protected is protected in Base
    base.m_private = 3; // not okay: m_private is private in Base
 
    Pri pri;
    pri.m_public = 1; // not okay: m_public is now private in Pri
    pri.m_protected = 2; // not okay: m_protected is now private in Pri
    pri.m_private = 3; // not okay: m_private is inaccessible in Pri
 
    return 0;
}
*/