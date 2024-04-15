#include <iostream>
#include <vector>

// 11. �ڵ� ���� �� �����غ� ����..

class NotImplemented {};


class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }

	void draw()
	{
		std::cout << "mutex lock\n";
		draw_imp();
		std::cout << "mutex unlock\n";
	}

	// �����Լ� : �Ļ� Ŭ������ override ���� ������ �⺻ ������ �����ϰڴٴ� �ǵ�
	// ���������Լ� : �Ļ� Ŭ������ �ݵ�� override �϶�� �����ϴ� ��

protected:
	virtual void draw_imp() = 0;
public:

	// clone �� ���
	// 1. ���� �����Լ��� �ص� �ǰ�(������ ��Ģ ���)
	// 2. �Ʒ� ó�� ����� ����� ������ ���(�⺻ ������ ���� �߻�)
	// => override ���� �ʰ�, ��뵵 ���� ������ ok
	// => override �ϰ�,     ��� �ϸ� ok.
	// => override ���� �ʰ�, ����ϸ� ���� �߻�.
	
//	virtual Shape* clone() = 0;
	virtual Shape* clone() { throw NotImplemented(); }

	// 
//	virtual int get_area() const = 0; // �̷��� �ص� �ǰ�.
	virtual int get_area() const { return -1; } // �⺻ ������ ���и� ��Ÿ���� �� ��ȯ
	

};





class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Rect\n"; }

	// ���� ��ȯ�� ��Ģ
	// => �����Լ� override �ÿ� ��ȯ Ÿ���� �����Ҽ� �ֽ��ϴ�.
	// => ��, ��Ӱ����� Ÿ�Ը� �����մϴ�.
	Rect* clone() override { return new Rect(*this); }
};

// Rect* p1 = new Rect;
// Rect* p2 = p1->clone();

class Circle : public Shape
{
public:
	void draw_imp() override  { std::cout << "draw Circle\n"; }

	Circle* clone() override { return new Circle(*this); }
};


int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// 1. ���ο� ������ �߰��Ǹ� �Ʒ��� "��ü����" �κ��� ���ؾ�(�߰�) �մϴ�.
		// => ��ü�� ������ OCP�� �����ϰ� �Ҽ� ������� ?
		// => "�߻� ���丮" ������ ����ϸ� �˴ϴ�. (3���� ����)

		// 2. "Undo/Redo" ����� �߰��Ϸ��� ��� �ؾ� �ұ�� ?
		// => "Command" ������ ����ϸ� �˴ϴ�.(3����)

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
			v.push_back(v[k]->clone());
		}
	}
}
