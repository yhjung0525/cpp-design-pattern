// 2_메뉴1.cpp  - 55 page
#include <iostream>

// C언어에서 프로그램이란 ?
// 1. main 함수의 1번째 줄부터 순차적으로 실행되는 실행 흐름
// 
// 2. 실행흐름을 변경하려면 "제어문(if, switch)" 사용
// 3. 실행흐름을 반복하려면 "반복문" 사용
// 4. 프로그램을 기능별로 분리하려면 "함수" 사용
// 5. 프로그램의 기본 단위는 "함수"

// 장점 : CPU 가 동작하는 방식과 동일
//       빠르고, 메모리 사용량도 적다

// 단점 : 유지보수가 어렵다
//		  확장성이 없고, 새로운 요소가 추가되면 변화가 많아진다.

// 아래 코드에서 새로운 메뉴가 추가되면 ?
// 각 메뉴에 하위 메뉴가 있다면



int main()
{
	// C 언어로 만든 메뉴 예제

	printf("1. 김밥\n");
	printf("2. 라면\n");
	printf("메뉴를 선택하세요 >> ");

	int cmd;
	std::cin >> cmd;

	switch (cmd)
	{
	case 1: break;
	case 2: break;
	}

}

// github.com/codenuri/mobis 에서 

// DAY2.zip 과 server.zip 받으시면 됩니다.
