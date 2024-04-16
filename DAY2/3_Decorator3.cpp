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

//	DrawFlower flower(&pic);
	DrawFlower flower(&frame); // 기능이 추가된 객체에 다시 기능추가		
							   // 현재는 에러!!
							   // "복습 하실때 현재 클래스 구조를 그림을 그려서"
							   // 왜 에러인지, 해결책은 무엇인지 생각해 보세요
								// => Decorator4.cpp 에서 해결
	flower.draw();

}