#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// ��ü���� ���α׷�
// => ��� ���� ��ü�̴�.
// => �޴��� ��Ÿ���� "Ÿ��"�� ���� ���� �Ѵ�.

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

		_getch(); // �ƹ� Ű�� ������ ���� ���. 
	}
};

int main()
{
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);

	m1.command(); // �޴� ����
}




