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

// 오늘의 핵심 
// => 변하지 않은 코드에서 변하는 코드를 분리하는 것

// 변하는 코드를 분리하는 방법
// 1. 가상함수로 분리 => template method 패턴, 변하는 것을 소유!!!

// 2. 다른 클래스로 분리 => 정책 클래스의 설계
// => 정책 클래스를 어떻게 교체 할것인가 
// 2.1 인터페이스를 만들어서 교체 하자 : strategy 패턴 => 실행시간 교체 가능. 
// 2.2 template 인자로 분리하자.      : policy base design(C++만의 기술)
//									   23개 패턴에 포함 안됨.
//									   가상함수가 아니라서 빠르지만,  실행시간 교체가 안됨

vector<int, MyAllocator<int>> v;	// v 실행중에 메모리 할당 정책 교체 안됨

Edit e;
LimitDigitValidator v1(5);
LimitDigitValidator v2(15);
e.set_validator(&v1);
e.set_validator(&v2);	// strategy는  실행시간 교체 가능.
