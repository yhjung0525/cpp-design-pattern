#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// �޴�6 : �������� ���� ��. root->submenu(1)->add() �� �Ϸ��� ĳ���� �ʿ�
// �޴�7 : ���Ǽ��� ���� ��. root->submenu(1)->add() �� �Ϸ��� ĳ���� ���� ��밡��

// ���ܸ� ���� Ŭ����
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

	// �Ʒ� ��� �Լ��� PopupMenu ���� �ʿ��� �Լ�����
	// "���Ǽ�" �� ���ؼ� BaseMenu ���� ������ �߰� �մϴ�.
	// => ��, ����Ʈ ������ ���� ����.
	// => �ݵ��, PopupMenu ���� override �ؾ� �մϴ�.
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
		std::cout << get_title() << " �޴��� ���õ�\n";

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
			std::cout << sz + 1 << ". ����\n";
			std::cout << "�޴��� �����ϼ��� >> ";

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
	PopupMenu* pm1 = new PopupMenu("���� ����");

	root->add(pm1);
	root->add(new MenuItem("��Ÿ ����", 1));

	pm1->add(new MenuItem("RED", 11));

	// �޴�6 �� �ٸ���, �Ʒ� ó�� ĳ���� ���� ��밡�� �մϴ�.
	root->submenu(0)->add(new MenuItem("GREEN", 12));  


	root->command();

}



