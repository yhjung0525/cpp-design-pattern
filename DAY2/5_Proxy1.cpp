// 실습해 보시는 분은 
// 1. visual studio 한개를 더실행하세요
// 2. server.zip 압축 풀고, 새로운 vs 에서 열어 보세요
// 3. vs에서 32bit 환경에서만 빌드 가능합니다.

#define USING_GUI
#include "cppmaster.h"

// Step1. C 스타일!
// 현재 코드의 단점
// 1. 모든 클라이언트 개발자가 IPC 기술을 알아야 한다.
// 2. server/client 약속인 1, 2 라는 숫자(명령코드)를 외워야 한다.


int main()
{
	// 1. 서버의 핸들을 얻어 옵니다.
	int server = ec_find_server("Calc");

	std::cout << "서버 번호 : " << server << std::endl;

	// 2. 서버에 명령코드와 파라미터를 전달합니다.
	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





