#include <iostream>
#include <vector>
#include <string>

// COMPOSITE 패턴 정리

// 1. 복합 객체는 개별객체 뿐 아니라 복합객체 자신도 보관 가능하다.
// => 공통의 기반 클래스가 필요 하다.

class Item
{
	std::string name;
public:
	Item(const std::string& name) : name(name) {}

	virtual ~Item() {}

	// File 과 Folder 모두 크기를 구할수 있습니다.
	// 메뉴 예제의 command 와 유사!
	virtual int get_size() = 0;
};

class File : public Item
{
	int size;
public:
	File(const std::string& name, int size) : Item(name), size(size) {}

	// 파일은 자신만의 크기가 있다..
	int get_size() override { return size; }
};


class Folder : public Item
{
	std::vector<Item*> v;
public:
	Folder(const std::string& name) : Item(name) {}

	void add(Item* item) { v.push_back(item); }

	// Folder 의 크기 
	// => 자신이 가진 모든 요소의 크기의 합.
	int get_size() override
	{
		int sz = 0;

		for (auto p : v)
			sz += p->get_size();

		return sz;
	}
};





int main()
{
	Folder* root = new Folder("ROOT");
	Folder* fo1 = new Folder("A");
	Folder* fo2 = new Folder("B");

	root->add(fo1);
	root->add(fo2);

	File* f1 = new File("a.txt", 10);
	File* f2 = new File("b.txt", 20);

	fo1->add(f1);
	root->add(f2);

	// 파일은 자신만의 크기는 있습니다.
	// 폴더는 자신만의 크기는 없지만 크기를 구할수 있습니다.
	std::cout << f2->get_size() << std::endl; // 20
	std::cout << fo1->get_size() << std::endl; // 10
	std::cout << root->get_size() << std::endl; // 30
}


