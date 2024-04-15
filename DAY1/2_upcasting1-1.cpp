#include <iostream>

class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Animal a;
	Dog d;

	Animal* p = &a;

	// static_cast 
	Dog* pd = static_cast<Dog*>(p);

	std::cout << pd << std::endl;

}











