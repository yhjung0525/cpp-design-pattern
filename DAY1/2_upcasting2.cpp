// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
	// upcasting Ȱ�� #1. ������ �����ϴ� �����̳�.
	std::vector<Dog*>    v1;	// Dog ��ü�� �����ϴ� �����̳�!
	std::vector<Animal*> v2;	// ����(���� ��� Ŭ������ ����ϴ� Ÿ��)
								// �� �����ϴ� �����̳�
								// => ��� ���� ������ �����ϰڴٴ� �ǵ�
}