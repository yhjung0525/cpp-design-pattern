#define USING_GUI
#include "cppmaster.h"

// Step2. Proxy 클래스 도입

// proxy 패턴 : 기존 요소의 대행자를 만드는 패턴
// remote-proxy : 원격지 서버에 대한 대행자

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
	// Client 제작자들은 서버 제작자가 만들어준 위 클래스(Calc) 만 사용하면 됩니다.
	// "IPC 관련" 기술이 없어도 됩니다.
	// Calc 가 결국 서버에 대한 대행자(Proxy) 입니다.
	Calc* calc = new Calc;

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}





