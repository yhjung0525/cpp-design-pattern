#include <iostream>

class Animal
{
public:
	// non-virtual : static binding 해달라는 의미
	void cry1() { std::cout << "Animal Cry1" << std::endl; }

		
	// virtual function : dynamic binding 해달라는 의미. 
	//					  컴파일 시간이 아닌 실행시간에 어느 함수를 호출할지 결정해 달라.
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; }
};

class Dog : public Animal
{
public:
	void cry1()         { std::cout << "Dog Cry1" << std::endl; }
	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; }
};

int main()
{
	Animal a;
	Dog d;
	Animal* p = &d;

	p->cry1(); // static binding. 무조건 포인터 타입으로 호출 
	p->cry2(); // dynamic binding 실행시간 메모리 조사후 함수 결정
}
// godbolt.org 사이트 접속해서 왼쪽 창에 위 코드 넣어 보세요

