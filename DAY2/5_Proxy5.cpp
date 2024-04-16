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

	// DLL ���ο��� "new" �� ����ؼ� Proxy�� �����˴ϴ�.
	// ���̻� �ʿ���ٸ� �����ؾ� �մϴ�.
	delete calc; // ?? ���� �ڵ� �ϱ�� ??

}





