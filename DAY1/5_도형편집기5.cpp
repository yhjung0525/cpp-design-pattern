#include <iostream>
#include <vector>


class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }

	virtual int get_area() const { return 0; }

	virtual void draw() { std::cout << "draw Shape\n"; }
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

class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw Triangle\n"; }
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
			for (auto p : v)
				p->draw();	
		}
		else if (cmd == 8)
		{
			std::cout << "���° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			// k��° ������� ������ �����ؼ� ���ο� ������ �����Ŀ� v �� �߰�
			// ��� �ؾ� �ұ�� ??
			// k ��° ������� ������ � �����ϱ�� ?

			// �Ʒ� ó�� ������� ������, �Ʒ� �ڵ�� OCP �� �����Ҽ� �����ϴ�.
			// => ���ο� ������ �߰��Ǹ� �Ʒ� �ڵ�� ����(�߰�)�Ǿ�� �մϴ�.
			if (dynamic_cast<Rect*>(v[k]) != 0)
			{
				v.push_back(new Rect( *v[k] ) );
			}
			else if (dynamic_cast<Circle*>(v[k]) != 0)
			{
				v.push_back(new Circle(*v[k]));
			}
		}
	}
}
