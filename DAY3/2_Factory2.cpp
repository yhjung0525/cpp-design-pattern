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

	// �ڽ��� ��ü�� ����� static ��� �Լ��� ���� �����ϰ� Ȱ��ɼ� �ֽ��ϴ�.
	static Shape* Create() { return new Rect; }
};

// Rect ��ü�� �����ϴ� 2���� ���
// 1. Shape* p1 = new Rect;			// �ݵ�� Ŭ���� �̸��� �˾ƾ� �մϴ�.
// 2. Shape* p2 = Rect::Create();	// Ŭ���� �̸��� ����, �Լ� �ּҸ� 
									// �˾Ƶ� �˴ϴ�

// C++ ������ "Ŭ�����̸�" �� �ڷᱸ���� �����Ҽ� ����, �Լ����ڷ� ����Ҽ��� �����ϴ�.
// => v.push_back("Rect"); => ���ڿ��� �����Ѱ�. ���ڿ� "Rect"�δ� ��ü���� ����.
// 
// ������ "�Լ� ������" �� �����Ҽ� �ֽ��ϴ�.       
// => v.push_back(&Rect::Create); 
// => foo( &Rect::Create);   









class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }
};



class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape* (*)();
	std::map<int, CREATOR> create_map;

public:
	void Register(int type, CREATOR c)
	{
		create_map[type] = c;
	}

	// �Ʒ� �ڵ�� ������ ����� ������, Ŭ���� �̸��� ������� �ʽ��ϴ�.
	// => ���ο� ������ �߰��Ǿ, �ڵ� ������ �ʿ� �����ϴ�.
	Shape* Create(int type)
	{
		Shape* p = nullptr;
			
		auto ret = create_map.find(type);

		if (ret != create_map.end())
		{
			p = ret->second(); // ret->second �� value �̹Ƿ� �Լ������� �Դϴ�
		}

		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// ���忡 ��ǰ(����)�� ��� �մϴ�.
	factory.Register(1, &Rect::Create);
	factory.Register(2, &Circle::Create);




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




