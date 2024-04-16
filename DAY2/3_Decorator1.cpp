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

class DrawFlower : public Picture
{
public:
	DrawFlower(const std::string& url) : Picture(url) {}

	void draw()
	{
		std::cout << "&&&&&&&&&&&&&&&&&&&\n"; // �߰��� ���
		Picture::draw();					  // ���� ��� ���
		std::cout << "&&&&&&&&&&&&&&&&&&&\n"; // �߰��� ���
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

	// �� �ڵ�� 
	// 1. �ٿ�ε�� �׸�(pic)�� ����� �߰��Ǵ� ���� �ƴ϶�!!
	// 2. �߰��� ����� ����ϱ� ���� �ٽ� �׸��� �ٿ�ε� �ϰ� �˴ϴ�.
	// 3. ����, ���ڿ� �� �׸��� ���ÿ� �߰��Ҽ��� �����ϴ�.

	// ��� : ��ü�� �ƴ� Ŭ������ ����� �߰��ϴ� ��

}