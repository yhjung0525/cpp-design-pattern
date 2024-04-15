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

	// �Ʒ� �ڵ带 ������ ������
	// �Ʒ� ���� �ڵ尡 �ִٸ� p�� ����Ű�� ����
	// �����߿� ����ɼ� �ֽ��ϴ�.
	// => ��, �����Ҷ� ����ɼ� �����Ƿ�
	//    ������ �ð����� p�� ����Ű�� ��ü�� � �������� �˼� �����ϴ�.
//	if (������Է� == 1) p = &d;

	// static_cast : ������ �ð� ĳ����. 
	// => p�� ����Ű�� ���� Dog ���� �����Ҽ� ����!!!
	// => ����, ��Ӱ����� Ÿ���̸� ������ ���!!
	// => p�� ����Ű�� ���� Dog �� �ƴ϶� �����ϴµ�, ��ȯ�� �ּ� ����
	//    ������ �ɼ� �ִ�.
	Dog* pd = static_cast<Dog*>(p);

	std::cout << pd << std::endl;

}











