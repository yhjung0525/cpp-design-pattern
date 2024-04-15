#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 객체지향 프로그램
// => 모든 것은 객체이다.
// => 메뉴를 나타내는 "타입"을 먼저 설계 한다.

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}

	std::string get_title() const { return title; }

	// 메뉴 선택시 호출될 함수
	void command()
	{
		std::cout << get_title() << " 메뉴가 선택됨\n";

		_getch(); // 아무 키나 누를때 까지 대기. 
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	m1.command(); // 메뉴 선택
}




