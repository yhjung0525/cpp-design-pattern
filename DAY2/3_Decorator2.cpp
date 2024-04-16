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

// 상속 : 클래스에 기능을 추가하는 것
// 포함 : 객체에 기능을 추가할수 있다.

class DrawFrame
{
	Picture* pic;	// 핵심 : 포인터 또는 참조로 포함
					//        외부에 "이미 존재하는 객체"를 가리키겠다는 의도
					//        "값 타입" 으로 하면 안됩니다.
public:
	DrawFrame(Picture* p) : pic(p) {}

	void draw()
	{
		std::cout << "===================\n"; // 추가된 기능
		pic->draw();						  // 이미 존재하던 객체 pic 의 기능사용
		std::cout << "===================\n"; // 추가된 기능
	}
};


int main()
{
	Picture pic("www.naver.com/a.png");
//	pic.draw();

	DrawFrame frame(&pic); // 이미 존재하는 객체 pic 에 
						   // "frame을 그리는 기능" 을 추가하겠다는 의미.
	frame.draw();
}