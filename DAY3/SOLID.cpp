// LSP ( Liskov Substitution Principle )
// => 기반 클래스가 사용되는 자리에 파생 클래스를 보낼수 있어야 한다.

class Animal {};
class Dog : public Animal {};

void fn(Animal* p) {}

Dog d;
fn(&d); // LSP  만족!!

//====================================
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

// DIP : Dependency Inversion Principle (의존관계 역전의 법칙)
// => 구체적인 클래스에 의존하지 말고, 인터페이스(추상)에 의존해라.
class People
{
public:
	void useCamera(HDCamera*) {} // bad. 교체 불가능.
	void useCamera(ICamera*) {} // good. 교체 가능.
};


// SRP : Single Responsible Principle
//  => 하나의 클래스는 하나의 책임만

// OCP : Open  Close Principle

// 객체지향 설계시 지켜야 하는 5개의 원칙
// SOLID : SRP, OCP, LSP, ISP, DIP


// 디자인 패턴의 핵심

// 1. 변하지 않은 코드에서 변하는 것을 분리 하는것
// 1-1. 변하는 것을 가상함수로 : template method, factory method
// 1-1. 변하는 것을 다른 클래스로 : strategy, state, builder


// 2. 간접층을 도입해서 문제를 해결하는 것
// 왜.. 간접층을 만드는가에 따라 패턴의 이름이 달라 집니다.
// 
// 사용자	===============> stack ================> list
//									=> 인터페이스의 변경 : adapter
// 
// 사용자	===============> MP3   ================> IMP3
//									=> Update 를 위해서 : bridge
// 
// 사용자	===============> Calc  ================> Server
//									=> 다양한 의도를 가진 대행자 : proxy
// 
// 사용자	===============> TCPServer ============> Socket, IPAddress
//									=> 사용법을 단순화 하기 위해 : facade

// 명령의 캡슐화 : command
// 통보, 열거, 방문 : observer, iterator, visitor, chain of responsibility
// 객체의 저장 : memento
// => 교재 마지막 페이지 참고

// iterpretor 패턴 : 컴파일러 파서 만들때 사용했던 패턴, 지금의 거의 사용되지 않음. 