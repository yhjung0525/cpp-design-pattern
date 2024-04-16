// Decorator - 65 page
#include <iostream>
#include <string>

// 인터넷에서 그림을 download 해서 화면에 그리는 함수
class Picture
{
	std::string url;
public:
	Picture(const std::string& url) : url(url)
	{
		// 인터넷에서 그림을 download 하는 코드.
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

	DrawFlower flower(&pic);
	flower.draw();

}