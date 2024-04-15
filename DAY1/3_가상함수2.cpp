#include <iostream>

class Base
{
public:
//	~Base() {}	// �̷����ϸ� ����!! (main �ּ� ����)
	virtual ~Base() {}	// �ٽ� : ��� ��� Ŭ������ �Ҹ��ڴ� virtual �̾���Ѵ�
						// ��� Ŭ���� �Ҹ��ڰ� virtual �̸�
						// ��� �Ļ� Ŭ������ �Ҹ��ڴ� �ڵ����� virtual �Դϴ�.
};

class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{
//	Derived d;

//	Derived* p = new Derived;	
//	delete p;

	// �� �ڵ���� ������ �����ϴ�. �׷���, �Ʒ� �ڵ带 ������ ������
	Base* p = new Derived;
	
	delete p;	// ������ : Derived �Ҹ��� ȣ�� �ȵ�.

	// "delete p" ���� ��ü�� �ı� �ǹǷ� �Ҹ��ڸ� ȣ���ؾ� �մϴ�.
	// => �Ҹ��ڵ� �ᱹ �Լ� �̹Ƿ�, "p->�Ҹ���()" �Դϴ�.
	// => �׷���, �Ҹ��ڰ� �����Լ��� �ƴϸ� static binding 
	// => ���� p�� Ÿ���� Base* �̹Ƿ� "Base �Ҹ���" ȣ��˴ϴ�.
	// => �ذ�å : ����� ����ϴ� ��� �Ҹ��ڴ� dynamic binding �ϵ���
	//            �ؾ� �մϴ�.
	//			  Base �� �Ҹ��ڸ� virtual ��!!  
}	
