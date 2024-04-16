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

	// DLL ���ο��� "new" �� ����ؼ� Proxy�� �����˴ϴ�.
	// ���̻� �ʿ���ٸ� �����ؾ� �մϴ�.
//	delete calc; // ?? ���� �ڵ� �ϱ�� ??

	ICalc* calc1 = reload_proxy();
	calc1->AddRef();		// ��Ģ 1. Proxy �� �����ϸ� ������� ����

	ICalc* calc2 = calc1;
	calc2->AddRef();		// ��Ģ 2. Proxy �����͸� �����ϸ� ������� ����

	calc2->Release();		// ��Ģ 3. �����Ͱ� ���̻� �ʿ������ ������� ����

	std::cout << "=============\n";
	calc1->Release();	// <========= ��������� 0�̹Ƿ��̶� �ı�.
	std::cout << "=============\n";
}





