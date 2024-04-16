#define USING_GUI
#include "cppmaster.h"

// Step3. 약한 결합(교체 가능한 설계)

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }
	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
	// 아래 처럼 만들면 Proxy 와 Client 간에 강한 결합이 됩니다.
	// Proxy 가 update 되면 아래 소스도 변경되어야 합니다.
	// (클라이언트 소스를 변경하고다시 컴파일)
//	Calc* calc = new Calc;

	// Client 는 Proxy 사용시 교체 가능하게 약한 결합이 되어야 한다.

	ICalc* calc = ? ; // <== 이 부분이 핵심입니다.


	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}





