#include <iostream>
#include <string>


// Picture �� Picture�� ����� �߰��ϴ� ��ü(Decorator) �� ������ �������̽��� �ʿ�
// => ��ø�� ��� �߰��� ����
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
class DrawFrame : public IDraw
{
	IDraw* pic;
public:
	DrawFrame(IDraw* p) : pic(p) {}

	void draw()
	{
		std::cout << "===================\n";
		pic->draw();
		std::cout << "===================\n";
	}
};

class DrawFlower : public IDraw
{
	IDraw* pic;
public:
	DrawFlower(IDraw* p) : pic(p) {}

	void draw()
	{
		std::cout << "&&&&&&&&&&&&&&&&&&&\n";
		pic->draw();
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