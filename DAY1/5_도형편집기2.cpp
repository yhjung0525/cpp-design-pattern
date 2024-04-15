#include <iostream>
#include <vector>

class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};
int main()
{
	std::vector<Shape*> v; 

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)      v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v) // Shape* p �ε�
				p->draw();   // Shape �ȿ��� draw()�� ����.
		}
	}
}
// �� ���ڵ尡 ���� �ϱ�� ?
// => p->draw() ���� p �� Shape* �ε�, Shape �ȿ��� draw �� ����.
// 
// �ذ�å�� ����� ?? 
// 1. Shape* �� p �� Rect* �Ǵ� Circle* �� ĳ���� �ؼ� �������. ==> ���� �̷��� ����������
// ==> �̷��� �Ϸ��� p �� � ������ ����Ű���� ���� �ʿ�(dynamic_cast)
// ==> if �� ���. 
// ==> OCP �����Ҽ� ����.
// 
// 2. Shape �ȿ��� draw() �� ������. ==> ��..
