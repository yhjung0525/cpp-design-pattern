// 32bit 빌드 ( x86 )

#define USING_GUI
#include "cppmaster.h"

// 이벤트 처리 함수는 반드시 인자로 int 4개를 받아야 합니다.
int foo(int hwnd, int msg, int a, int b) 
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON " << hwnd << std::endl; break;
	case WM_KEYDOWN:     std::cout << "KEYDOWN " << hwnd << std::endl; break;
	}
	return 0;
}
int main()
{
	int h1 = ec_make_window(foo, "A"); 
	int h2 = ec_make_window(foo, "B");

	// h1 를 h2의 자식윈도우로 부착하려면
	ec_add_child(h2, h1); // B 윈도우에  "A를 자식" 윈도우로 부착


	// 프로그램을 종료 하지 말고, 
	// 윈도우에서 발생하는 이벤트를 처리하기 위해 호출
	ec_process_message(); 
}

