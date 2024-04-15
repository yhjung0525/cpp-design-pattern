#include <iostream>

class Animal
{
public:
	int age;
	virtual ~Animal() {} // 모든 기반 클래스는 소멸자가 가상함수 이어야
						 // 합니다.
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

	// 아래 코드를 생각해 보세요
	// 아래 같은 코드가 있다면 p가 가리키는 곳은
	// 실행중에 변경될수 있습니다.
	// => 즉, 실행할때 변경될수 있으므로
	//    컴파일 시간에는 p가 가리키는 객체가 어떤 종류인지 알수 없습니다.
//	if (사용자입력 == 1) p = &d;

	// static_cast : 컴파일 시간 캐스팅. 
	// => p가 가리키는 곳이 Dog 인지 조사할수 없다!!!
	// => 따라서, 상속관계의 타입이면 무조건 허용!!
	// => p가 가리키는 곳이 Dog 가 아니라도 성공하는데, 반환된 주소 사용시
	//    문제가 될수 있다.
//	Dog* pd = static_cast<Dog*>(p);

	// dynamic_cast : 실행시간 캐스팅
	// => 실행시간에 p가 가리키는 곳을 조사후
	// => Dog 가 맞는 경우만 주소 반환
	// => Dog 가 아니면 0 반환
	// => "가상함수가 있는 타입" 에 대해서만 사용가능.
	//    타입 정보를 "가상함수 테이블" 에 보관하기 때문에. 
	Dog* pd = dynamic_cast<Dog*>(p);

	std::cout << pd << std::endl;

}











