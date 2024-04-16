#define USING_GUI
#include "cppmaster.h"

// Step4. ���� ���� ����

// Ŭ���̾�Ʈ �����ڴ� ���� �����ڿ��� 2���� ������ �޾ƾ� �մϴ�.
// ICalc.h       : �������̽��� �ִ� ��� ����
// CalcProxy.dll : Proxy �� ��� ���� ��� ( Proxy Update �ÿ� �� DLL �� �ٽù���)

// Ŭ���̾�Ʈ �������� �ڵ�� �Ʒ��� �����ϴ�.
#include "ICalc.h"

ICalc* reload_proxy()
{
	// 1. ���� ��� load
	void* addr = ec_load_module("CalcProxy.dll"); 
							// linux : dlopen()   Windows : LoadLibrary()
	// 2. ��ӵ� �Լ� ã��
	using F = ICalc* (*)();

	F f = (F)ec_get_function_address(addr, "CreateProxy");
							// linux : dlsym()	windows : GetProcAddress()

	// 3. ��ӵ� �Լ��� ȣ���ϸ� Proxy �� �����˴ϴ�.
	ICalc* calc = f();
	return calc;
	// ���Լ� ��ü�� ���� �����ڰ� ���� ���� �ص� �˴ϴ�.
}

int main()
{
	ICalc* calc = reload_proxy();

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}





