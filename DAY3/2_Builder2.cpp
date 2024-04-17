// 2_Builder
#include <iostream>
#include <string>


typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{} ��� ����


// ����ڰ� � ������ �����ϴ°��� ���� ĳ������ ����, ������, �Ź��� �ٸ��ϴ�.
struct IBuilder
{
	virtual Hat makeHat() = 0;
	virtual Uniform makeUniform() = 0;
	virtual Shoes   makeShoes() = 0;
	virtual ~IBuilder() {}
};

// ���� ������ ������ �����մϴ�
class American : public IBuilder
{
public:
	virtual Hat makeHat() { return Hat("�߱�����"); }
	virtual Uniform makeUniform() { return Uniform("Ƽ����"); }
	virtual Shoes   makeShoes() { return Shoes("����"); }
};

class Korean : public IBuilder
{
public:
	virtual Hat makeHat() { return Hat("��"); }
	virtual Uniform makeUniform() { return Uniform("�Ѻ�"); }
	virtual Shoes   makeShoes() { return  Shoes("¤��"); }
};


class Director
{
	IBuilder* builder = nullptr;
public:
	void set_builder(IBuilder* p) { builder = p; }

	Character construct()
	{
		// ĳ���͸� ����� ������ ���� �մϴ�.
		// => ������, �� ������ ����� �޶����ϴ�.
		Character c;
		c = c + builder->makeHat();
		c = c + builder->makeUniform();
		c = c + builder->makeShoes();
		return c;
	}
};
int main()
{
	American a;
	Korean k;
	Director d;
	d.set_builder(&k); // ���� ������ �����Ҷ����� "����" �� ��ü �մϴ�.

	Character c = d.construct();
	std::cout << c << std::endl;

}