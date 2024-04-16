#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

struct Stream
{
	virtual void Write(const std::string&) = 0;
	virtual ~Stream() {}
};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void Write(const std::string& s)
	{
		printf("%s ����\n", s.c_str());
	}
};

int main()
{
//	FileStream fs("a.txt");
//	fs.Write("AAA");

	// ���Ͽ� ���� ��ȣȭ �ؼ� ���� ����� �ʿ� �ϴ�.

	// ��� 1. ����Ÿ�� ���� ��ȣȭ ���Ŀ� Write() �Լ��� ����.

	// ��� 2. FileStream ���� ���� �Ļ��� Ŭ������ �����Ŀ�
	//         EncryptWrite() ���� �޼ҵ� �߰�
	// => FileStream �� �ƴ϶� NetworkStream ���� ��� Ŭ������ �Ļ� Ŭ���� �ʿ�
	// => ��ȣȭ �� �ƴ϶� ������� ����� �ʿ��ϸ� �Ļ� Ŭ������ ��� �þ��
	//    2�� ����� ��ø�� ����� ����

	// ��� 3. Decorator ������ Ȱ��
	
	FileStream fs("a.txt");

	EncryptDecorator ed(&fs);
	ed.Write("AAA");		// 1. ��ȣȭ ����� �����ϰ�
							// 2. fs.Write()�� ����

	ZipDecorator zd(&ed);
	zd.Write("AAA");		// 1. �������� �����ϰ� (�߰��� ���)
							// 2. ed.Write()�� ����
}