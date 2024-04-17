#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	virtual Shape* Clone() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }

	Rect* Clone() override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }

	Rect* Clone() override { return new Rect(*this); }
};



class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> create_map;

public:
	void Register(int type, Shape* c)
	{
		create_map[type] = c;
	}

	Shape* Create(int type)
	{
		Shape* p = nullptr;

		auto ret = create_map.find(type);

		if (ret != create_map.end())
		{
			p = ret->second->Clone(); // ��ϵ� �ߺ��� ���纻 ����
		}

		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();


	// �Ʒ� �ڵ�� �ᱹ factory ��  "1. ��ü   2. Ŭ����" �� ����ϴ� �ڵ��Դϴ�.
	// => ��Ȯ���� "�Լ� ������" ���������, �ǹ̻����δ� "Ŭ�������" �Դϴ�.
	// => ��ü�� �����ϱ� ���ؼ� �Լ� �����͸� ����ϹǷ�
//	factory.Register(1, &Rect::Create);
//	factory.Register(2, &Circle::Create);

	// Ŭ���� ����, ���ֻ��Ǵ� ��ü�� ����� ���ô�.
	// => �ߺ��� �Ǵ� ��ü�� �����ؼ�, ���忡 ����Ŀ�
	// => �ߺ��� ���纻�� ���ؼ� ��ü ����(prototype ����)
	Rect* redRect = new Rect; // ������, ũ�Ⱑ 10�� �簢���̶�� ����
	Rect* blueRect = new Rect; 
	Circle* redCircle = new Circle;

	factory.Register(1, redRect);
	factory.Register(2, blueRect);
	factory.Register(3, redCircle);




	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd > 0 && cmd < 8)
		{
			Shape* p = factory.Create(cmd);

			if (p != nullptr)
				v.push_back(p);
		}

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}




