//������1.cpp - 3page
#include <iostream>

// �ٽ� 1. ������ ȣ���� ��Ȯ�� ����
//     2. ��� Ŭ������ ����Ʈ �����ڰ� ������.. 

class Base
{
public:
//	Base() { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:	
	/*
	// ������ڵ�		// �����Ϸ��� ������ �ڵ�
	Derived()			// Derived() : Base()
	{ 
		std::cout << "Derived()" << std::endl; 
	}
	Derived(int a)		// Derived(int a) : Base()  <== �����Ϸ��� �߰���
	{											// �ڵ�� �׻� ����Ʈ	������ȣ��	
		std::cout << "Derived(int)" << std::endl; 
	}
	*/
	
	// �ٽ� : ��� Ŭ������ ����Ʈ �����ڰ� ���ٸ� �ݵ�� �Ļ� Ŭ��������
	//       �ٸ� �����ڸ� ���� ȣ���ؾ� �մϴ�.

	Derived()      : Base(0) {}
	Derived(int a) : Base(a) {}


	~Derived()		
	{ 
		std::cout << "~Derived()" << std::endl; 

		// Base::~Base()  // �Ҹ��ڴ� Derived ������ ���� ����ǰ�, ��� Ŭ���� �Ҹ���ȣ�� 
	}
};
int main()
{
	Derived d1;		// call Derived::Derived()
//	Derived d2(5);

}

