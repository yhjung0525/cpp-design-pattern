// 1_Flyweight - 167
#include <iostream>
#include <string>
#include <map>

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	// Image ��ü�� ������ �ִ� static ��� �Լ�
	// => Image ��ü�� �����ϴ� �ڵ尡 �Ѱ� ������ �̷�� ����.
	
	// inline static : static ��� ����Ÿ�� Ŭ���� �ܺ� ������ ��� �˴ϴ�.(C++17)
	inline static std::map<std::string, Image*> image_map;

	static Image* Create(const std::string& url)
	{
		Image* img = nullptr;

		auto p = image_map.find(url);

		if (p == image_map.end())
		{
			img = new Image(url);
			image_map[url] = img;
		}
		else
			img = image_map[url];

		return img;
	}
};





int main()
{
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

}



