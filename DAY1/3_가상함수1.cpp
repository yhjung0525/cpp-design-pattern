#include <iostream>

// 함수 override : 기반 클래스 함수를 파생 클래스가 다시 만드는 것. 

class Animal
{
public:
	void cry1() { std::cout << "Animal Cry1" << std::endl; } 
};
class Dog : public Animal
{
public:	
	void cry1() { std::cout << "Dog Cry1" << std::endl; } 
};
int main()
{
	Animal a;
	Dog d;
	Animal* p = &d; 

//	if (사용자 입력 == 1) p = &a;

	p->cry1();
}

// p->cry1() 의 코드를 실제 "어느 함수와 연결" 할것인가 ?
// => 함수 바인딩(binding) 이라고 합니다.

// 1. static binding : 컴파일 시간에 컴파일러가 결정하는 것. 
// => 컴파일 시간에는 p 가 가리키는 객체가 실제 어떤 객체인지 알수 없다.
// => 컴파일러가 아는 것은 p 자체의 타입이 "Animal*" 이라는 것만 알수 있다
// => 따라서, 컴파일러가 결정하면 무조건 "Animal Cry1" 호출
// => 빠르지만, 논리적이지 않다.
// => C++, C# 의 기본 바인딩 방식
// 
// 2. dynamic binding : 컴파일 시간에 p가 가리키는 메모리를 조사하는
//                      기계어 코드 생성
// => 실행할때, 메모리 조사해서, 객체가 어떤 객체냐에 따라 함수 결정
// => p가 Dog를 가리켰다면 "Dog Cry1" 호출. 
// => 느리지만, 논리적인 방식
// => Java, Python, Swift 등의 대부분의 객체지향 언어의 방식.
//    C++/C# 의 virtual function 

