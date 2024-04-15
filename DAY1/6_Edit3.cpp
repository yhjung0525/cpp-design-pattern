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

	//--------------------------------------------
	IValidator* pval = nullptr; // 값의 유효성을 판단할 객체
public:
	void set_validator(IValidator* p) { pval = p; }
	//--------------------------------------------

	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13 && (pval == nullptr || pval->is_complete(data)) ) break;

			if ( pval == nullptr || pval->validate(data, c) ) // 값의 유효성 판단을 다른 객체의 위임
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

// Edit 의 Validation 정책을 변경하려면
// => Validation 정책을 담은 "정책 클래스" 를 만들어서 전달하면 됩니다.
class LimitDigitValidator : public IValidator
{
	int max_value;
public:
	LimitDigitValidator(int n) : max_value(n) {}

	bool validate(const std::string& s, char c) override
	{
		return s.size() < max_value && isdigit(c);
	}
};

int main()
{	
	Edit e;
	LimitDigitValidator v(5);
	e.set_validator(&v);

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


