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

// 상속을 사용한 기능의 추가
class DrawFrame : public Picture
{
public:
	DrawFrame(const std::string& url) : Picture(url) {}
	
	void draw()
	{
		std::cout << "===================\n"; // 추가된 기능
		Picture::draw();					  // 원래 기능 사용
		std::cout << "===================\n"; // 추가된 기능
	}
};
int main()
{
	Picture pic("www.naver.com/a.png");
	pic.draw();

	DrawFrame frame("www.naver.com/a.png");
	frame.draw();
}