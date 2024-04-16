#define USING_GUI
#include "cppmaster.h"

// Step2. Proxy Ŭ���� ����

// proxy ���� : ���� ����� �����ڸ� ����� ����
// remote-proxy : ������ ������ ���� ������

class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); } 

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b);	}
};

int main()
{
	// Client �����ڵ��� ���� �����ڰ� ������� �� Ŭ����(Calc) �� ����ϸ� �˴ϴ�.
	// "IPC ����" ����� ��� �˴ϴ�.
	// Calc �� �ᱹ ������ ���� ������(Proxy) �Դϴ�.
	Calc* calc = new Calc;

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}





