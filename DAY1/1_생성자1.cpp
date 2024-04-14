//생성자1.cpp - 3page
#include <iostream>

class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:						
	// 사용자코드		// 컴파일러가 변경한 코드
	Derived()			// Derived() : Base()
	{ 
		std::cout << "Derived()" << std::endl; 
	}
	Derived(int a)		// Derived(int a) : Base()  <== 컴파일러가 추가한
	{											// 코드는 항상 디폴트	생성자호출	
		std::cout << "Derived(int)" << std::endl; 
	}
	
	~Derived()		
	{ 
		std::cout << "~Derived()" << std::endl; 

		// Base::~Base()  // 소멸자는 Derived 구현이 먼저 실행되고, 기반 클래스 소멸자호출 
	}
};
int main()
{
	Derived d1;		// call Derived::Derived()
//	Derived d2(5);

}

