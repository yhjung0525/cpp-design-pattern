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
	ICalc* calc = reload_proxy();

	// DLL 내부에서 "new" 를 사용해서 Proxy가 생성됩니다.
	// 더이상 필요없다면 제거해야 합니다.
	delete calc; // ?? 좋은 코드 일까요 ??

}





