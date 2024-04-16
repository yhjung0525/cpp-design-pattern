#define USING_GUI
#include "cppmaster.h"

// Step4. 동적 모듈로 배포

// 클라이언트 제작자는 서버 제작자에게 2개의 파일을 받아야 합니다.
// ICalc.h       : 인터페이스가 있는 헤더 파일
// CalcProxy.dll : Proxy 가 담긴 동적 모듈 ( Proxy Update 시에 이 DLL 을 다시배포)

// 클라이언트 제작자의 코드는 아래와 같습니다.
#include "ICalc.h"

ICalc* reload_proxy()
{
	// 1. 동적 모듈 load
	void* addr = ec_load_module("CalcProxy.dll"); 
							// linux : dlopen()   Windows : LoadLibrary()
	// 2. 약속된 함수 찾기
	using F = ICalc* (*)();

	F f = (F)ec_get_function_address(addr, "CreateProxy");
							// linux : dlsym()	windows : GetProcAddress()

	// 3. 약속된 함수를 호출하면 Proxy 가 생성됩니다.
	ICalc* calc = f();
	return calc;
	// 이함수 자체를 서버 제작자가 만들어서 배포 해도 됩니다.
}

int main()
{
	ICalc* calc = reload_proxy();

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}





