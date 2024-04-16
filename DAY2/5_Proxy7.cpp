#include <memory>

int main()
{
	// C++ 표준에 이미 스마트 포인터 "std::shared_ptr" 이 있는데
	// 이것을 사용하면 안되나요 ?

	std::shared_ptr<ICalc> sp1( reload_proxy() );
				// => proxy 주소를 보관하고 있다가
				// => sp1 이 파괴될때 소멸자에서 delete 하게 됩니다.
				// => 우리가 원하는 것은 "delete" 가 아니라
				//    Release()를 호출해서 DLL 내부에서 delete 을 하고 싶은것!!!
	
	sp<ICalc> sp2 = reload_proxy();
				// => 생성자에서 "AddRef" 호출
				// => 소멸자에서 "Release" 호출
				// => delete 는 DLL 내부에서!!

	// 그래서 C++ 표준에 스마트 포인터가 있지만,
	// 많은 오픈소스에서 다시 자신들만의 스마트 포인터를 제공합니다.
}