// 2_Builder
#include <iostream>
#include <string>


typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{} 라고 가정


// 사용자가 어떤 국가를 선택하는가에 따라 캐릭터의 모자, 유니폼, 신발은 다릅니다.
struct IBuilder
{
	virtual Hat makeHat() = 0;
	virtual Uniform makeUniform() = 0;
	virtual Shoes   makeShoes() = 0;
	virtual ~IBuilder() {}
};

// 이제 국가별 빌더를 제공합니다
class American : public IBuilder
{
public:
	virtual Hat makeHat() { return Hat("야구모자"); }
	virtual Uniform makeUniform() { return Uniform("티셔츠"); }
	virtual Shoes   makeShoes() { return Shoes("구두"); }
};

class Korean : public IBuilder
{
public:
	virtual Hat makeHat() { return Hat("갓"); }
	virtual Uniform makeUniform() { return Uniform("한복"); }
	virtual Shoes   makeShoes() { return  Shoes("짚신"); }
};


class Director
{
	IBuilder* builder = nullptr;
public:
	void set_builder(IBuilder* p) { builder = p; }

	Character construct()
	{
		// 캐릭터를 만드는 공정은 동일 합니다.
		// => 하지만, 각 공정의 결과는 달라집니다.
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
	d.set_builder(&k); // 국가 선택을 변경할때마다 "빌더" 를 교체 합니다.

	Character c = d.construct();
	std::cout << c << std::endl;

}