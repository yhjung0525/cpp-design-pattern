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
	Dog* pd = static_cast<Dog*>(p);

	std::cout << pd << std::endl;

}











