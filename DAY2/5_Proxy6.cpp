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

	ICalc* calc1 = reload_proxy();
	calc1->AddRef();		

	ICalc* calc2 = calc1;
	calc2->AddRef();		

	calc2->Release();		

	std::cout << "=============\n";
	calc1->Release();	
	std::cout << "=============\n";
}





