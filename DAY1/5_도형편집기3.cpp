#include <iostream>
#include <vector>

// 3. ��� ������ ������ Ư¡�� �ݵ�� ��� Ŭ������ Shape ���� �־�� �Ѵ�.
// => �������� �䱸������ �ƴ�
// => ���������� �䱸 ����.

// 4. �Ļ� Ŭ������ override �ϰԵǴ� �Լ��� "�ݵ�� �����Լ�"�� ����Ǿ�� �Ѵ�.


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	// �Ʒ� ��� �Լ��� virtual �� �ұ�� ? non-virtual �� �ұ�� ?
	// => �Ļ�Ŭ������ override �� ���� �����ϴ�. non-virtual
	// => virtual�� �ص� ������ �ƴϰ�, ����� ���ۿ��� ���� ������
	// => �����Լ��� ������尡 �ֽ��ϴ�. �ʿ��Ҷ��� ����ؾ� �մϴ�.
	void set_color(int c) { color = c; }

	// �Ʒ� �Լ��� ��� ������ override �ϰ� �˴ϴ�. virtual �̾�� �մϴ�.
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
	}
}
