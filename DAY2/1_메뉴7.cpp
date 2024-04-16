#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 메뉴6 : 안전성을 위한 모델. root->submenu(1)->add() 를 하려면 캐스팅 필요
// 메뉴7 : 편의성을 위한 모델. root->submenu(1)->add() 를 하려면 캐스팅 없이 사용가능

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

	// 메뉴6 과 다르게, 아래 처럼 캐스팅 없이 사용가능 합니다.
	root->submenu(0)->add(new MenuItem("GREEN", 12));  


	root->command();

}



