#include <iostream>
 
class Fruit
{
public:
	// Note: we've moved FruitType inside the class, under the public access specifier
	enum FruitType
	{
		APPLE,
		BANANA,
		CHERRY
	};
 
private:
	FruitType m_type;
	int m_percentageEaten = 0;
 
public:
 
 
	Fruit(FruitType type) :
		m_type(type)
	{
	}
 
	FruitType getType() { return m_type;  }
	int getPercentageEaten() { return m_percentageEaten;  }
};
 
int main()
{
	// Note: we access the FruitType via Fruit now
	Fruit apple(Fruit::APPLE);
	
	if (apple.getType() == Fruit::APPLE)
		std::cout << "I am an apple";
	else
		std::cout << "I am not an apple";
	
	return 0;
}