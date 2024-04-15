#include <iostream>
#include <string>
#include <conio.h>

// Validation ��å�� ��ü(����) �����ؾ� �Ѵ�

class Edit
{
	std::string data;
public:
	// ���뼺�� �������� �и�
	// => ������ ���� �ڵ� �ӿ� �ִ� ���ؾ� �ϴ� �ڵ带 ã�´�.
	// => ���ؾ� �ϴ� �ڵ带 �����Լ��� �и��Ѵ�.

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

			if (validate(c)) // ������ �����Լ��� ����ؼ� ��ȿ�� �˻�
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

// ���ϴ� ���� �����Լ��� ����� �ڵ��� �ǵ�!
// => �����ϰ� ������ �Ļ� Ŭ������ ���� �����Լ��� override �϶�� ��
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


