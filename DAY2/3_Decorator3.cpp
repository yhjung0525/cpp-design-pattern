// Decorator - 65 page
#include <iostream>
#include <string>

// ���ͳݿ��� �׸��� download �ؼ� ȭ�鿡 �׸��� �Լ�
class Picture
{
	std::string url;
public:
	Picture(const std::string& url) : url(url)
	{
		// ���ͳݿ��� �׸��� download �ϴ� �ڵ�.
	}

	void draw() { std::cout << "draw " << url << std::endl; }
};

//===================================================
class DrawFrame
{
	Picture* pic;	
public:
	DrawFrame(Picture* p) : pic(p) {}

	void draw()
	{
		std::cout << "===================\n"; 
		pic->draw();						  
		std::cout << "===================\n"; 
	}
};

class DrawFlower
{
	Picture* pic;
public:
	DrawFlower(Picture* p) : pic(p) {}

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

//	DrawFlower flower(&pic);
	DrawFlower flower(&frame); // ����� �߰��� ��ü�� �ٽ� ����߰�		
							   // ����� ����!!
							   // "���� �ϽǶ� ���� Ŭ���� ������ �׸��� �׷���"
							   // �� ��������, �ذ�å�� �������� ������ ������
								// => Decorator4.cpp ���� �ذ�
	flower.draw();

}