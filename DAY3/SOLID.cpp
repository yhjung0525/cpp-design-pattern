// LSP ( Liskov Substitution Principle )
// => ��� Ŭ������ ���Ǵ� �ڸ��� �Ļ� Ŭ������ ������ �־�� �Ѵ�.

class Animal {};
class Dog : public Animal {};

void fn(Animal* p) {}

Dog d;
fn(&d); // LSP  ����!!

//====================================
class stack : public std::list<int>
{
public:
	void push(int n) { std::list<int>::push_back(n); }

	void push_front(int n) { throw 1; } // ��� Ŭ���� �Լ��� ������� ���ϰ�
};
stack s;
s.push_front(10); // ������� ���ϰ� ����.


void f2(std::list<int>* p)
{
	p->push_front(10);
}
stack s2;
f2(&s2); // ���� �߻�.. ��� Ŭ������ ���Ǵ� �ڸ���
// �Ļ� Ŭ������ ���´µ�. ���ܰ� ���Դ�.
// LSP ����



// �Ʒ� �������̽��� ���� ���� ���̽� �ϱ�� ?
struct IMP3
{
	virtual void Play() = 0;
	virtual void Stop() = 0;
	virtual void TakePicture() = 0;
};

// ISP : Interface Surrogate Principle (�������̽� �ݸ��� ��Ģ)
// => �������̽��� ��ɺ��� �и��ض�.
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

// DIP : Dependency Inversion Principle (�������� ������ ��Ģ)
// => ��ü���� Ŭ������ �������� ����, �������̽�(�߻�)�� �����ض�.
class People
{
public:
	void useCamera(HDCamera*) {} // bad. ��ü �Ұ���.
	void useCamera(ICamera*) {} // good. ��ü ����.
};


// SRP : Single Responsible Principle
//  => �ϳ��� Ŭ������ �ϳ��� å�Ӹ�

// OCP : Open  Close Principle

// ��ü���� ����� ���Ѿ� �ϴ� 5���� ��Ģ
// SOLID : SRP, OCP, LSP, ISP, DIP


// ������ ������ �ٽ�

// 1. ������ ���� �ڵ忡�� ���ϴ� ���� �и� �ϴ°�
// 1-1. ���ϴ� ���� �����Լ��� : template method, factory method
// 1-1. ���ϴ� ���� �ٸ� Ŭ������ : strategy, state, builder


// 2. �������� �����ؼ� ������ �ذ��ϴ� ��
// ��.. �������� ����°��� ���� ������ �̸��� �޶� ���ϴ�.
// 
// �����	===============> stack ================> list
//									=> �������̽��� ���� : adapter
// 
// �����	===============> MP3   ================> IMP3
//									=> Update �� ���ؼ� : bridge
// 
// �����	===============> Calc  ================> Server
//									=> �پ��� �ǵ��� ���� ������ : proxy
// 
// �����	===============> TCPServer ============> Socket, IPAddress
//									=> ������ �ܼ�ȭ �ϱ� ���� : facade

// ����� ĸ��ȭ : command
// �뺸, ����, �湮 : observer, iterator, visitor, chain of responsibility
// ��ü�� ���� : memento
// => ���� ������ ������ ����

// iterpretor ���� : �����Ϸ� �ļ� ���鶧 ����ߴ� ����, ������ ���� ������ ����. 