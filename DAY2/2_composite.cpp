#include <iostream>
#include <vector>
#include <string>

// COMPOSITE ���� ����

// 1. ���� ��ü�� ������ü �� �ƴ϶� ���հ�ü �ڽŵ� ���� �����ϴ�.
// => ������ ��� Ŭ������ �ʿ� �ϴ�.

class Item
{
	std::string name;
public:
	Item(const std::string& name) : name(name) {}

	virtual ~Item() {}

	// File �� Folder ��� ũ�⸦ ���Ҽ� �ֽ��ϴ�.
	// �޴� ������ command �� ����!
	virtual int get_size() = 0;
};

class File : public Item
{
	int size;
public:
	File(const std::string& name, int size) : Item(name), size(size) {}

	// ������ �ڽŸ��� ũ�Ⱑ �ִ�..
	int get_size() override { return size; }
};


class Folder : public Item
{
	std::vector<Item*> v;
public:
	Folder(const std::string& name) : Item(name) {}

	void add(Item* item) { v.push_back(item); }

	// Folder �� ũ�� 
	// => �ڽ��� ���� ��� ����� ũ���� ��.
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

	// ������ �ڽŸ��� ũ��� �ֽ��ϴ�.
	// ������ �ڽŸ��� ũ��� ������ ũ�⸦ ���Ҽ� �ֽ��ϴ�.
	std::cout << f2->get_size() << std::endl; // 20
	std::cout << fo1->get_size() << std::endl; // 10
	std::cout << root->get_size() << std::endl; // 30
}


