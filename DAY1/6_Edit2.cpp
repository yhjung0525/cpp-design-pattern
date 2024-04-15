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



int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


