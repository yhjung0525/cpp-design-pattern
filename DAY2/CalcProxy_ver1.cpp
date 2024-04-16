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

// Client 제작자는 DLL 내부에 있는 클래스이름(Calc) 을
// 알지도 못하고, 알필요도 없고, 사용해도 안됩니다.
// DLL 내부에 약속된 함수를 만들고 객체 생성을 합니다.
// => 새로운 Proxy DLL 을 만들때도 아래 함수는 반드시 있어야 합니다.
extern "C" __declspec(dllexport)
ICalc * CreateProxy()
{
	return new Calc;
}

// 빌드 하는법 
// visual studio 가 제공하는 C++ 컴파일러 이름 : cl.exe 입니다.

// cl CalcProxy.cpp /LD	 /link  user32.lib   gdi32.lib   kernel32.lib
// 
// => CalcProxy.dll 생성
// 
// /LD 가 DLL로 빌드하라는 옵션

// 윈도우 시작 버튼 => visual studio 2022 폴더 => 개발자 명령 프롬프트 선택
