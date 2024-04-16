#define USING_GUI
#include "cppmaster.h"

// Step2. Proxy 클래스 도입

// proxy 패턴 : 기존 요소의 대행자를 만드는 패턴
// remote-proxy : 원격지 서버에 대한 대행자

// "proxy - skeleton(stub)" 이라는 용어가 많이 사용됩니다.
// proxy : 함수 호출을 "명령코드로 변경"해서 서버에 전달. 

// skeleton(stub) : 도착한 명령 코드를 다시 함수호출로 변경하는 코드
//				    서버에 있는 "handler" 함수

// 결국 "RPC(Remote Procedure Call)" 을 만드는 과정. 

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





