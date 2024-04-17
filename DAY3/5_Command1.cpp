#include <iostream>
#include <vector>
#include <stack>

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

// Undo/Redo ����� ����� ���ô�.
// => Undo �Ϸ��� ������� ��� ����� �����ؾ� �մϴ�.

// C���        : �޴� ���ý� �ؾ��� ���� �Լ��� �ۼ�
// Command ���� : �޴� ���ý� �ؾ��� ���� Ŭ������ �ۼ��϶�� �ǹ�

// ��� ����� ���Ѿ��ϴ� �������̽� 
struct ICommad
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}
	virtual ~ICommand() {}
};

// "�簢�� �߰�" �� ����� �����ϴ� ���
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

};






int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw();
		}
	}
}




