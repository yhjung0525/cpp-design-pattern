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


