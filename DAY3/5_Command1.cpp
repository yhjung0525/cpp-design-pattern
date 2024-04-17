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

// Undo/Redo 기능을 만들어 봅시다.
// => Undo 하려면 사용자의 모든 명령을 보관해야 합니다.

// C언어        : 메뉴 선택시 해야할 일을 함수로 작성
// Command 패턴 : 메뉴 선택시 해야할 일을 클래스로 작성하라는 의미

// 모든 명령이 지켜야하는 인터페이스 
struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}
	virtual ~ICommand() {}
};

// "사각형 추가" 를 기능을 수행하는 명령
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

	std::stack<ICommand*> cmd_stack; // undo 을 위해서 

	ICommand* command = nullptr;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			// 메뉴 선택시 기능을 직접 수행하거나, 함수를 호출하지 말고!!!
			// => 해당 기능을 수행하는 객체를 생성해서 기능을 수행한다.
			command = new AddRectCommand(v);
			command->execute();

			// undo 를 위해서 작업을 stack 에 보관
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
					delete command; // redo 하려면 delete 하지말고
									// redo_stack 에 보관하면 됩니다.
				}

			}

		}
	}
}




