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