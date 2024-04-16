#include <iostream>
#include <string>
#include <map>
#include "helper.h"

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	// ImageFactory 에서는 Image 객체를 생성할수 있어야 한다.
	// => private 접근 가능해야 한다.
	friend class ImageFactory;
};

// SRP : Single Responsibility Principle
// => 단일 책임의 원칙
// => 하나의 클래스는 하나의 책임만 가져야 한다.

// Image        : 그림을 다운로드해서 그리는 기능
// ImageFactory : Image 객체의 생성/공유 기능을 제공

class ImageFactory
{
	MAKE_SINGLETON(ImageFactory)

	std::map<std::string, Image*> image_map;
public:
	Image* Create(const std::string& url)
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
	ImageFactory& factory = ImageFactory::get_instance();

	Image* img1 = factory.Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.Create("www.naver.com/a.png");
	img2->Draw();

}



