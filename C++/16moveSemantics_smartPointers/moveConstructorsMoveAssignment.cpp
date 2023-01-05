#include<iostream>
template<class T>
class Auto_ptr3
{
	T* m_ptr;
public:
	Auto_ptr3(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}
 
	~Auto_ptr3()
	{
		delete m_ptr;
	}
 
	// Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr3(const Auto_ptr3& a)
	{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}
 
	// Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr3& operator=(const Auto_ptr3& a)
	{
		// Self-assignment detection
		if (&a == this)
			return *this;
 
		// Release any resource we're holding
		delete m_ptr;
 
		// Copy the resource
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
 
		return *this;
	}
 
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

template<class T>
class Auto_ptr4
{
	T* m_ptr;
public:
	Auto_ptr4(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}
 
	~Auto_ptr4()
	{
		delete m_ptr;
	}
 
	// Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr4(const Auto_ptr4& a)
	{
        std::cerr<<"copy:constractor\n";
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}
 
	// Move constructor
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr4(Auto_ptr4&& a) noexcept
		: m_ptr(a.m_ptr)
	{
        std::cerr<<"move:constractor\n";
		a.m_ptr = nullptr; // we'll talk more about this line below
	}
 
	// Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr4& operator=(const Auto_ptr4& a)
	{
        std::cerr<<"copy:operator ================================\n";
        
		// Self-assignment detection
		if (&a == this)
			return *this;
 
		// Release any resource we're holding
		delete m_ptr;
 
		// Copy the resource
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
 
		return *this;
	}
 
	// Move assignment
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr4& operator=(Auto_ptr4&& a) noexcept
	{
        std::cerr<<"move:operator ================================\n";
		// Self-assignment detection
		if (&a == this)
			return *this;
 
		// Release any resource we're holding
		delete m_ptr;
 
		// Transfer ownership of a.m_ptr to m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // we'll talk more about this line below
 
		return *this;
	}
 
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};
template<class T>
class Auto_ptr5
{
	T* m_ptr;
public:
	Auto_ptr5(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}
 
	~Auto_ptr5()
	{
		delete m_ptr;
	}
 
	// Copy constructor -- no copying allowed!
	Auto_ptr5(const Auto_ptr5& a) = delete;
 
	// Move constructor
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr5(Auto_ptr5&& a) noexcept
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;
	}
 
	// Copy assignment -- no copying allowed!
	Auto_ptr5& operator=(const Auto_ptr5& a) = delete;
 
	// Move assignment
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr5& operator=(Auto_ptr5&& a) noexcept
	{
		// Self-assignment detection
		if (&a == this)
			return *this;
 
		// Release any resource we're holding
		delete m_ptr;
 
		// Transfer ownership of a.m_ptr to m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
 
		return *this;
	}
 
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};
class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};
 
// Auto_ptr3<Resource> generateResource()
// {
// 	Auto_ptr3<Resource> res(new Resource);
// 	return res; // this return value will invoke the copy constructor
// }
Auto_ptr4<Resource> generateResource()
{
	Auto_ptr4<Resource> res(new Resource);
	return res; // this return value will invoke the move constructor
}
 
int main()
{
	Auto_ptr4<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the copy assignment
 
	return 0;
}