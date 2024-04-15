#include <iostream>

// �Լ� override : ��� Ŭ���� �Լ��� �Ļ� Ŭ������ �ٽ� ����� ��. 

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

//	if (����� �Է� == 1) p = &a;

	p->cry1();
}

// p->cry1() �� �ڵ带 ���� "��� �Լ��� ����" �Ұ��ΰ� ?
// => �Լ� ���ε�(binding) �̶�� �մϴ�.

// 1. static binding : ������ �ð��� �����Ϸ��� �����ϴ� ��. 
// => ������ �ð����� p �� ����Ű�� ��ü�� ���� � ��ü���� �˼� ����.
// => �����Ϸ��� �ƴ� ���� p ��ü�� Ÿ���� "Animal*" �̶�� �͸� �˼� �ִ�
// => ����, �����Ϸ��� �����ϸ� ������ "Animal Cry1" ȣ��
// => ��������, �������� �ʴ�.
// => C++, C# �� �⺻ ���ε� ���
// 
// 2. dynamic binding : ������ �ð��� p�� ����Ű�� �޸𸮸� �����ϴ�
//                      ���� �ڵ� ����
// => �����Ҷ�, �޸� �����ؼ�, ��ü�� � ��ü�Ŀ� ���� �Լ� ����
// => p�� Dog�� �����״ٸ� "Dog Cry1" ȣ��. 
// => ��������, ������ ���
// => Java, Python, Swift ���� ��κ��� ��ü���� ����� ���.
//    C++/C# �� virtual function 

