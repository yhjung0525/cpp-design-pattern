#include <iostream>
#include <vector>

// �Ŀ� ����Ʈ ���� ���α׷��� ������ ���ô�.

// 1. ��� ������ Ÿ��ȭ �ϸ� ���ϴ�.

// 2. ��� ������ ������ ��� Ŭ������ �ִٸ� ��� ������ ��� �����Ҽ� �ִ�.
// => ��� ������ ������ Ư¡�� ������ �ȴ�.

class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
//	int x, y, w, h; �����ڷ� �ʱ�ȭ.
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
//	std::vector<Rect*> v;  // Rect �� �����Ҽ� �ִ� vector
	std::vector<Shape*> v; // ��� ������ �����Ҽ� �ִ� vector

}

