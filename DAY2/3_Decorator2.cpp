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

// ��� : Ŭ������ ����� �߰��ϴ� ��
// ���� : ��ü�� ����� �߰��Ҽ� �ִ�.

class DrawFrame
{
	Picture* pic;	// �ٽ� : ������ �Ǵ� ������ ����
					//        �ܺο� "�̹� �����ϴ� ��ü"�� ����Ű�ڴٴ� �ǵ�
					//        "�� Ÿ��" ���� �ϸ� �ȵ˴ϴ�.
public:
	DrawFrame(Picture* p) : pic(p) {}

	void draw()
	{
		std::cout << "===================\n"; // �߰��� ���
		pic->draw();						  // �̹� �����ϴ� ��ü pic �� ��ɻ��
		std::cout << "===================\n"; // �߰��� ���
	}
};


int main()
{
	Picture pic("www.naver.com/a.png");
//	pic.draw();

	DrawFrame frame(&pic); // �̹� �����ϴ� ��ü pic �� 
						   // "frame�� �׸��� ���" �� �߰��ϰڴٴ� �ǹ�.
	frame.draw();
}