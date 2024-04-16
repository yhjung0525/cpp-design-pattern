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

// ����� ����� ����� �߰�
class DrawFrame : public Picture
{
public:
	DrawFrame(const std::string& url) : Picture(url) {}
	
	void draw()
	{
		std::cout << "===================\n"; // �߰��� ���
		Picture::draw();					  // ���� ��� ���
		std::cout << "===================\n"; // �߰��� ���
	}
};
int main()
{
	Picture pic("www.naver.com/a.png");
	pic.draw();

	DrawFrame frame("www.naver.com/a.png");
	frame.draw();
}