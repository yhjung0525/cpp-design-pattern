#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 분리하는 2가지 방법
// 1. 가상함수로 분리 - template method 패턴(Edit2.cpp)
// 
// 2. 변하는 것을 다른 클래스로 분리 
// => 교체 가능해야 하므로 인터페이스를 먼저 설계

// 모든 Validation 정책은 아래 인터페이스를 구현해야 합니다.
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }
	virtual ~IValidator() {}
};

// 주민 등록 번호 : 941   1   확인




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

			if (c == 13) break; 

			if (isdigit(c))
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n"
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


