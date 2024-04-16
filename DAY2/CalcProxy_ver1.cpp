// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }
	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// Client �����ڴ� DLL ���ο� �ִ� Ŭ�����̸�(Calc) ��
// ������ ���ϰ�, ���ʿ䵵 ����, ����ص� �ȵ˴ϴ�.
// DLL ���ο� ��ӵ� �Լ��� ����� ��ü ������ �մϴ�.
// => ���ο� Proxy DLL �� ���鶧�� �Ʒ� �Լ��� �ݵ�� �־�� �մϴ�.
extern "C" __declspec(dllexport)
ICalc * CreateProxy()
{
	return new Calc;
}

// ���� �ϴ¹� 
// visual studio �� �����ϴ� C++ �����Ϸ� �̸� : cl.exe �Դϴ�.

// cl CalcProxy.cpp /LD	 /link  user32.lib   gdi32.lib   kernel32.lib
// 
// => CalcProxy.dll ����
// 
// /LD �� DLL�� �����϶�� �ɼ�

// ������ ���� ��ư => visual studio 2022 ���� => ������ ��� ������Ʈ ����
