#include <iostream>
#include <string>
#include <conio.h>

// GUI Widget 인 Edit 를 생각해 봅시다.
// => 입력값을 validation 하는 기능 추가

class Edit
{
	std::string data;
public:
	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; // enter 키 입력

			if (isdigit(c))
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


