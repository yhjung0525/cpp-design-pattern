#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

ICalc* reload_proxy()
{
	void* addr = ec_load_module("CalcProxy.dll");
	using F = ICalc * (*)();
	F f = (F)ec_get_function_address(addr, "CreateProxy");
	ICalc* calc = f();
	return calc;
}
// 참조계수를 자동으로 관리하는 스마트 포인터를 도입합니다
// => 이런 용도로 안드로이드안에 sp 라는 스마트 포인터가 있습니다.
template<typename T> 
class sp 
{
	T* obj;
public:
	sp(T* p = nullptr) : obj(p) { if (obj) obj->AddRef(); }
	sp(const sp& other) : obj(other.obj) { if (obj) obj->AddRef(); }
	~sp() { if (obj) obj->Release(); }

	// raw pointer 와 동일하게 사용하기 위해 -> 와 * 연산자 재정의
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main()
{
	sp<ICalc> calc1 = reload_proxy();
	sp<ICalc> calc2 = calc1;
	 
	std::cout << calc1->Add(10, 20); // (calc1.operator->())->Add(10,20)
}


/*
int main()
{
	ICalc* calc1 = reload_proxy();
	calc1->AddRef();		

	ICalc* calc2 = calc1;
	calc2->AddRef();		

	calc2->Release();		

	std::cout << "=============\n";
	calc1->Release();	
	std::cout << "=============\n";
}


*/


