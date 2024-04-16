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
// ��������� �ڵ����� �����ϴ� ����Ʈ �����͸� �����մϴ�
// => �̷� �뵵�� �ȵ���̵�ȿ� sp ��� ����Ʈ �����Ͱ� �ֽ��ϴ�.
template<typename T> 
class sp 
{
	T* obj;
public:
	sp(T* p = nullptr) : obj(p) {}
	sp(const sp& other) : obj(other.obj) {}
	~sp() {}

	// raw pointer �� �����ϰ� ����ϱ� ���� -> �� * ������ ������
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};
int main()
{
	sp<ICalc> calc1 = new Calc;
	sp<ICalc> calc2 = calc1;

	std::cout << calc1->Add(10, 20) << std::endl;
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

