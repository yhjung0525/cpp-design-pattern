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

int main()
{
//	ICalc* calc = reload_proxy();

	// DLL 내부에서 "new" 를 사용해서 Proxy가 생성됩니다.
	// 더이상 필요없다면 제거해야 합니다.
//	delete calc; // ?? 좋은 코드 일까요 ??

	ICalc* calc1 = reload_proxy();
	calc1->AddRef();		// 규칙 1. Proxy 를 생성하면 참조계수 증가

	ICalc* calc2 = calc1;
	calc2->AddRef();		// 규칙 2. Proxy 포인터를 복사하면 참조계수 증가

	calc2->Release();		// 규칙 3. 포인터가 더이상 필요없으면 참조계수 감소

	std::cout << "=============\n";
	calc1->Release();	// <========= 참조계수가 0이므로이때 파괴.
	std::cout << "=============\n";
}





