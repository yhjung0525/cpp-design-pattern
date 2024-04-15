#include <iostream>
#include <string>
#include <conio.h>

// ���ϴ� ���� �и��ϴ� 2���� ���
// 1. �����Լ��� �и� - template method ����(Edit2.cpp)
// 
// 2. ���ϴ� ���� �ٸ� Ŭ������ �и� 
// => ��ü �����ؾ� �ϹǷ� �������̽��� ���� ����

// ��� Validation ��å�� �Ʒ� �������̽��� �����ؾ� �մϴ�.
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;

	virtual bool is_complete(const std::string& s) { return true; }

	virtual ~IValidator() {}
};

// �ֹ� ��� ��ȣ : 941   1   Ȯ��




class Edit
{
	std::string data;

	//--------------------------------------------
	IValidator* pval = nullptr; // ���� ��ȿ���� �Ǵ��� ��ü
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

			if ( pval == nullptr || pval->validate(data, c) ) // ���� ��ȿ�� �Ǵ��� �ٸ� ��ü�� ����
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

// Edit �� Validation ��å�� �����Ϸ���
// => Validation ��å�� ���� "��å Ŭ����" �� ���� �����ϸ� �˴ϴ�.
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


