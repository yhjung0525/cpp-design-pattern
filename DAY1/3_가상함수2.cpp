#include <iostream>

class Base
{
public:
//	~Base() {}	// 이렇게하면 버그!! (main 주석 참고)
	virtual ~Base() {}	// 핵심 : 모든 기반 클래스의 소멸자는 virtual 이어야한다
						// 기반 클래스 소멸자가 virtual 이면
						// 모든 파생 클래스의 소멸자는 자동으로 virtual 입니다.
};

class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
//	Derived d;

//	Derived* p = new Derived;	
//	delete p;

	// 위 코드들은 문제가 없습니다. 그런데, 아래 코드를 생각해 보세요
	Base* p = new Derived;
	
	delete p;	// 문제점 : Derived 소멸자 호출 안됨.

	// "delete p" 에서 객체가 파괴 되므로 소멸자를 호출해야 합니다.
	// => 소멸자도 결국 함수 이므로, "p->소멸자()" 입니다.
	// => 그런데, 소멸자가 가상함수가 아니면 static binding 
	// => 현재 p의 타입은 Base* 이므로 "Base 소멸자" 호출됩니다.
	// => 해결책 : 상속을 사용하는 경우 소멸자는 dynamic binding 하도록
	//            해야 합니다.
	//			  Base 의 소멸자를 virtual 로!!  
}	
