#include <iostream>
#include <string>
#include <conio.h>

// Validation 정책은 교체(변경) 가능해야 한다

class Edit
{
	std::string data;
public:
	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 속에 있는 변해야 하는 코드를 찾는다.
	// => 변해야 하는 코드를 가상함수로 분리한다.

	virtual bool validate(char c)
	{
		return true;
	}

	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; 

			if (validate(c)) // 별도의 가상함수를 사용해서 유효성 검사
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

// 변하는 것을 가상함수로 만드는 코드의 의도!
// => 변경하고 싶으면 파생 클래스를 만들어서 가상함수를 override 하라는 것
class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit e;
	NumEdit e;
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


