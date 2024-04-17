// LSP ( Liskov Substitution Principle )
// => 기반 클래스가 사용되는 자리에 파생 클래스를 보낼수 있어야 한다.

class Animal {};
class Dog : public Animal {};

void fn(Animal* p) {}

Dog d;
fn(&d); // LSP  만족!!


class stack : public std::list<int>
{
public:
	void push(int n) { std::list<int>::push_back(n); }

	void push_front(int n) { throw 1; } // 기반 클래스 함수를 사용하지 못하게
};
stack s;
s.push_front(10); // 사용하지 못하게 하자.


void f2(std::list<int>* p)
{
	p->push_front(10);
}
stack s2;
f2(&s2); // 예외 발생.. 기반 클래스가 사용되는 자리에
// 파생 클래스를 보냈는데. 예외가 나왔다.
// LSP 위반



// 아래 인터페이스는 좋은 인터 페이스 일까요 ?
struct IMP3
{
	virtual void Play() = 0;
	virtual void Stop() = 0;
	virtual void TakePicture() = 0;
};

// ISP : Interface Surrogate Principle (인터페이스 격리의 원칙)
// => 인터페이스는 기능별로 분리해라.
struct IMP3
{
	virtual void Play() = 0;
	virtual void Stop() = 0;
};
struct Picture
{
	virtual void TakePicture() = 0;
};
class GoodMP3 : public IMP3, public Picture
{
};

// DIP : Dependency Inversion Principle 
// => 구체적인 클래스에 의존하지 말고, 인터페이스(추상)에 의존해라.
class People
{
public:
	void useCamera(HDCamera*) {} // bad
	void useCamera(ICamera*) {} // good
};
// SRP : Single Responsible Principle
//  => 하나의 클래스는 하나의 책임만

// OCP : Open  Close Principle

// 객체지향 설계시 지켜야 하는 5개의 원칙
// SOLID : SRP, OCP, LSP, ISP, DIP