#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}

	std::string get_title() const { return title; }

	// �޴� ���ý� ȣ��� �Լ�
	void command()
	{
		std::cout << get_title() << " �޴��� ���õ�\n";

		_getch();
	}
};

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}

	void add(MenuItem* m) { v.push_back(m); }

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
};





int main()
{
	MenuItem m1("��ġ���",   11);
	MenuItem m2("�Ұ����", 12);

	PopupMenu kimbam("����");
	kimbam.add(&m1);
	kimbam.add(&m2);

	MenuItem m9("���", 21);

	
	PopupMenu pm("������ ���� �޴�");

	pm.add(&kimbam); // �ٽ�. !! �� �����غ�����
	pm.add(&m9);

	pm.command();
}




