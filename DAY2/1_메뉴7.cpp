#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 예외를 위한 클래스
class UnsupportedOperation {};


class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title)
		: title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	virtual void command() = 0;

	// 아래 멤버 함수는 PopupMenu 에만 필요한 함수지만
	// "편의성" 을 위해서 BaseMenu 에도 선언을 추가 합니다.
	// => 단, 디폴트 구현은 예외 전달.
	// => 반드시, PopupMenu 에서 override 해야 합니다.
	virtual BaseMenu* submenu(int idx) { throw UnsupportedOperation(); return 0; }
	virtual void add(BaseMenu* m)      { throw UnsupportedOperation(); }
};






class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		std::cout << get_title() << " 메뉴가 선택됨\n";

		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add(BaseMenu* m) { v.push_back(m); }

	void command()
	{
		while (1)
		{
			system("cls");

			auto sz = v.size();
			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". 종료\n";
			std::cout << "메뉴를 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			v[cmd - 1]->command();

		}


	}

	BaseMenu* submenu(int idx) { return v[idx]; }
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상 변경");

	root->add(pm1);
	root->add(new MenuItem("기타 설정", 1));

	pm1->add(new MenuItem("RED", 11));

	// 아래 기능에 대해서 생각해 봅시다
	// auto m1 = root->submenu(1); // "색상" PopupMenu 의 포인터 꺼내기

	// 아래 한줄에 대해서 생각해 보세요!!
	// => 현재 코드는 add 가 PopupMenu 에만 있으므로
	// => 아래 처럼 사용할수 없고, 캐스팅해야 합니다.
//	root->submenu(1)->add(new MenuItem("GREEN", 12));  // error

	static_cast<PopupMenu*>(root->submenu(1))->add(new MenuItem("GREEN", 12));  // error

	root->command();

}



