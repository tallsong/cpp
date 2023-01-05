#include <memory> // for std::unique_ptr
#include <iostream>
 
class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
 
	friend std::ostream& operator<<(std::ostream& out, const Resource &res)
	{
		out << "I am a resource\n";
		return out;
	}
};
 
// The function only uses the resource, so we'll accept a pointer to the resource, not a reference to the whole std::unique_ptr<Resource>
void useResource(Resource *res)
{
	if (res)
		std::cout << *res << '\n';
}
 
int main()
{
	auto ptr{ std::make_unique<Resource>() };
 
	useResource(ptr.get()); // note: get() used here to get a pointer to the Resource
 
	std::cout << "Ending program\n";
 
	return 0;
} // The Resource is destroyed here




/*

#include <memory> // for std::unique_ptr
#include<iostream> 
class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
	friend std::ostream& operator<<(std::ostream& out, const Resource &res)
	{
		out << "I am a resource\n";
		return out;
	}
};
 
void takeOwnership(std::unique_ptr<Resource> res)
{
     if (res)
          std::cout << *res << '\n';
} // the Resource is destroyed here
 
int main()
{
    auto ptr{ std::make_unique<Resource>() };
 
//    takeOwnership(ptr); // This doesn't work, need to use move semantics
    takeOwnership(std::move(ptr)); // ok: use move semantics
 
    std::cout << "Ending program\n";
 
    return 0;
}
*/