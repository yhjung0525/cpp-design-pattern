#include <vector>
#include <iostream>

template<typename T>
class MyAllocator
{
public:
	inline T* allocate(std::size_t sz) 
	{ 
		std::cout << "MyAllocator allocate\n";
		return new T[sz]; 
	}
	inline void deallocate(T* p, std::size_t sz)
	{ 
		std::cout << "MyAllocator deallocate\n";
		delete[] p; 
	}

	// STL �����̳ʿ� ���޵Ǵ� allocator ��å Ŭ������ �� 2�� �Լ��ܿ�
	// �Ʒ� 3���� �� �ʿ� �մϴ�.
	using value_type = T;
	MyAllocator() {}		// ����Ʈ ������
	template<typename U> MyAllocator(const MyAllocator<U>&) {} // generic ������
};

int main()
{
	std::vector<int, MyAllocator<int> > v;
	std::cout << "---------------------" << std::endl;
	v.resize(10);
	std::cout << "---------------------" << std::endl;

}

// ������ �ٽ� 
// => ������ ���� �ڵ忡�� ���ϴ� �ڵ带 �и��ϴ� ��

// ���ϴ� �ڵ带 �и��ϴ� ���
// 1. �����Լ��� �и� => template method ����, ���ϴ� ���� ����!!!

// 2. �ٸ� Ŭ������ �и� => ��å Ŭ������ ����
// => ��å Ŭ������ ��� ��ü �Ұ��ΰ� 
// 2.1 �������̽��� ���� ��ü ���� : strategy ���� => ����ð� ��ü ����. 
// 2.2 template ���ڷ� �и�����.      : policy base design(C++���� ���)
//									   23�� ���Ͽ� ���� �ȵ�.
//									   �����Լ��� �ƴ϶� ��������,  ����ð� ��ü�� �ȵ�

vector<int, MyAllocator<int>> v;	// v �����߿� �޸� �Ҵ� ��å ��ü �ȵ�

Edit e;
LimitDigitValidator v1(5);
LimitDigitValidator v2(15);
e.set_validator(&v1);
e.set_validator(&v2);	// strategy��  ����ð� ��ü ����.
