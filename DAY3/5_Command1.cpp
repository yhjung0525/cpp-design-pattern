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
struct ICommand
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

	void execute()  override {	v.push_back(new Rect); }

	bool can_undo() override { return true; }

	void undo()  override 
	{
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
};
class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	void execute()  override { v.push_back(new Circle); }

	bool can_undo() override { return true; }

	void undo()  override
	{
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
};


class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	void execute()  override 
	{ 
		for (auto s : v)
			s->draw();
	}

	bool can_undo() override { return true; }

	void undo()  override  { system("cls"); }
};




int main()
{
	std::vector<Shape*> v;

	std::stack<ICommand*> cmd_stack; // undo �� ���ؼ� 

	ICommand* command = nullptr;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			// �޴� ���ý� ����� ���� �����ϰų�, �Լ��� ȣ������ ����!!!
			// => �ش� ����� �����ϴ� ��ü�� �����ؼ� ����� �����Ѵ�.
			command = new AddRectCommand(v);
			command->execute();

			// undo �� ���ؼ� �۾��� stack �� ����
			cmd_stack.push(command);

		}

		else if (cmd == 2)
		{
			command = new AddCircleCommand(v);
			command->execute();

			cmd_stack.push(command);
		}
		else if (cmd == 9)
		{
			command = new DrawCommand(v);
			command->execute();

			cmd_stack.push(command);
		}
		else if (cmd == 0)
		{
			if (!cmd_stack.empty())
			{
				command = cmd_stack.top();
				cmd_stack.pop();

				if (command->can_undo())
				{
					command->undo();
					delete command; // redo �Ϸ��� delete ��������
									// redo_stack �� �����ϸ� �˴ϴ�.
				}

			}

		}
	}
}




