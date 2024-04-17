#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

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

	static Shape* Create() { return new Rect; }
};








class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }
};



class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)();
	std::map<int, CREATOR> create_map;

public:
	void Register(int type, CREATOR c)
	{
		create_map[type] = c;
	}

	Shape* Create(int type)
	{
		Shape* p = nullptr;

		auto ret = create_map.find(type);

		if (ret != create_map.end())
		{
			p = ret->second(); 
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




