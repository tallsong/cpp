class Base
{
public:
    int m_public; // can be accessed by anybody
protected:
    int m_protected; // can be accessed by Base members, friends, and derived classes
private:
    int m_private; // can only be accessed by Base members and friends (but not derived classes)
};
 
class Derived: public Base
{
public:
    Derived()
    {
        m_public = 1; // allowed: can access public base members from derived class
        m_protected = 2; // allowed: can access protected base members from derived class
        //m_private = 3; // not allowed: can not access private base members from derived class
    }
};
 
int main()
{
    Base base;
    base.m_public = 1; // allowed: can access public members from outside class
    // base.m_protected = 2; // not allowed: can not access protected members from outside class
    // base.m_private = 3; // not allowed: can not access private members from outside class
}