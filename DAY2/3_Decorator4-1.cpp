#include <iostream>
#include <string>

struct IDraw
{
	virtual void draw() = 0;
	virtual ~IDraw() {}
};

class Picture : public IDraw
{
	std::string url;
public:
	Picture(const std::string& url) : url(url)
	{
	}

	void draw() { std::cout << "draw " << url << std::endl; }
};

//===================================================

// ��� �߰� Ŭ�������� ������ Ư¡�� �ֽ��ϴ�.
// �̰�� ��� Ŭ������ �����ϴ� ���� �����ϴ�.
class Decorator : public IDraw
{
	int x, y; // �߰��׸��� ��ġ
	IDraw* pic;
public:
	Decorator(IDraw* p) : pic(p), x(0), y(0) {}

	void draw() { pic->draw(); }
};

class DrawFrame : public Decorator
{
public:
	DrawFrame(IDraw* p) : Decorator(p) {}

	void draw()
	{
		std::cout << "===================\n";
		Decorator::draw();
		std::cout << "===================\n";
	}
};

class DrawFlower : public Decorator
{
public:
	DrawFlower(IDraw* p) : Decorator(p) {}

	void draw()
	{
		std::cout << "&&&&&&&&&&&&&&&&&&&\n";
		Decorator::draw();
		std::cout << "&&&&&&&&&&&&&&&&&&&\n";
	}
};
int main()
{
	Picture pic("www.naver.com/a.png");

	DrawFrame frame(&pic);
	frame.draw();

	DrawFlower flower(&frame);
	flower.draw();
}