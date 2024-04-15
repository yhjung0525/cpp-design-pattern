#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class BaseMenu
{	
	std::string title;
public:
	BaseMenu(const std::string& title) 
		: title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	// 모든 메뉴는 선택될수 있다.
	virtual void command() = 0;
};





class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	// 메뉴 선택시 호출될 함수
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
};





int main()
{
	MenuItem m1("참치김밥",   11);
	MenuItem m2("소고기김밥", 12);

	PopupMenu kimbam("김밥류");
	kimbam.add(&m1);
	kimbam.add(&m2);

	MenuItem m9("라면", 21);

	
	PopupMenu pm("오늘의 점심 메뉴");

	pm.add(&kimbam); // 핵심. !! 잘 생각해보세요
	pm.add(&m9);

	pm.command();
}




