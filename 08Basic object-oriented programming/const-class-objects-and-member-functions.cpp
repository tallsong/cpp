#include <string>
 
class Something
{
private:
    std::string m_value;
 
public:
    Something(const std::string &value=""): m_value{ value } {}
 
    const std::string& getValue() const { return m_value; } // getValue() for const objects
    std::string& getValue() { return m_value; } // getValue() for non-const objects
};


int main()
{
	Something something{};
	something.getValue() = "Hi"; // calls non-const getValue();
 
	const Something something2{};
	something2.getValue(); // calls const getValue();
 
	return 0;
}