//생성자1.cpp - 3page
#include <iostream>

// 핵심 1. 생성자 호출의 정확한 원리
//     2. 기반 클래스에 디폴트 생성자가 없을때.. 

class Base
{
public:
//	Base() { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:	
	/*
	// 사용자코드		// 컴파일러가 변경한 코드
	Derived()			// Derived() : Base()
	{ 
		std::cout << "Derived()" << std::endl; 
	}
	Derived(int a)		// Derived(int a) : Base()  <== 컴파일러가 추가한
	{											// 코드는 항상 디폴트	생성자호출	
		std::cout << "Derived(int)" << std::endl; 
	}
	*/
	
	// 핵심 : 기반 클래스에 디폴트 생성자가 없다면 반드시 파생 클래스에서
	//       다른 생성자를 직접 호출해야 합니다.

	Derived()      : Base(0) {}
	Derived(int a) : Base(a) {}


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

