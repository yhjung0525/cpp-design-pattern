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
	Dog d;
	Dog* p1 = &d;		// ok
//	int* p2 = &d;		// error
	
	// 핵심 1. upcasting 개념
	// => 파생 클래스 객체의 주소를 기반 클래스 포인터에 담을수 있다
	Animal* p3 = &d;	// ok

	// 핵심 2. 기반 클래스 포인터로는 기반 클래스 멤버만 접근 가능.
	// => C++ 컴파일러는 컴파일 시간에 "포인터의 타입" 으로만 확인
	p3->age = 10;   // ok
	p3->color = 10; // error


	// 핵심 3. 파생 클래스 멤버에 접근하려면 
	// => 포인터를 파생 클래스 타입으로 캐스팅해야 한다.
	// => 단, 이경우 반드시 p3가 가리키는 곳이 Dog 라는 확신이 있어야 한다.
	static_cast<Dog*>(p3)->color = 10; // ok

	// 핵심 4. p3 가 가리키는 곳이 Dog 인지 조사할수 없나요 ?
	// => dynamic_cast 사용
	// => 단, 조사하는 코드를 사용하는 것은 아주 나쁜 디자인 입니다.
}











