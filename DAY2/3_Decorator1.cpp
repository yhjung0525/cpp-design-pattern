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

class DrawFlower : public Picture
{
public:
	DrawFlower(const std::string& url) : Picture(url) {}

	void draw()
	{
		std::cout << "&&&&&&&&&&&&&&&&&&&\n"; // 추가된 기능
		Picture::draw();					  // 원래 기능 사용
		std::cout << "&&&&&&&&&&&&&&&&&&&\n"; // 추가된 기능
	}
};
int main()
{
	Picture pic("www.naver.com/a.png");
	pic.draw();

	DrawFrame frame("www.naver.com/a.png");
	frame.draw();

	DrawFlower flower("www.naver.com/a.png");
	flower.draw();

	// 위 코드는 
	// 1. 다운로드된 그림(pic)에 기능이 추가되는 것이 아니라!!
	// 2. 추가된 기능을 사용하기 위해 다시 그림을 다운로드 하게 됩니다.
	// 3. 또한, 액자와 꽃 그림을 동시에 추가할수도 없습니다.

	// 상속 : 객체가 아닌 클래스에 기능을 추가하는 것

}