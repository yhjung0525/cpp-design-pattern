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


struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}
	virtual ~ICommand() {}
};

class AddCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	void execute()  override { v.push_back( create_shape() ); }
	bool can_undo() override { return true; }
	void undo()  override
	{
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
	// 객체를 만들기 위한 인터페이스를 정의 하고 사용하지만
	// 어떤 종류의 객체인지는 파생 클래스가 결정.
	virtual Shape* create_shape() = 0;
};

class AddRectCommand : public AddCommand
{
public:
	AddRectCommand(std::vector<Shape*>& v) : AddCommand(v) {}

	Shape* create_shape() override { return new Rect; }
};
class AddCircleCommand : public AddCommand
{
public:
	AddCircleCommand(std::vector<Shape*>& v) : AddCommand(v) {}

	Shape* create_shape() override { return new Circle; }
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

	void undo()  override { system("cls"); }
};




int main()
{
	std::vector<Shape*> v;

	std::stack<ICommand*> cmd_stack;  

	ICommand* command = nullptr;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			command = new AddRectCommand(v);
			command->execute();

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
					delete command; 
				}

			}

		}
	}
}




