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

	// STL 컨테이너에 전달되는 allocator 정책 클래스는 위 2개 함수외에
	// 아래 3개가 더 필요 합니다.
	using value_type = T;
	MyAllocator() {}		// 디폴트 생성자
	template<typename U> MyAllocator(const MyAllocator<U>&) {} // generic 생성자

};

int main()
{
	std::vector<int, MyAllocator<int> > v;

	std::cout << "---------------------" << std::endl;

	v.resize(10);

	std::cout << "---------------------" << std::endl;

}