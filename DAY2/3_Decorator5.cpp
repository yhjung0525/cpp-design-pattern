#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// �پ��� Stream Ŭ������ ������ �������̽� ����
struct Stream
{
	virtual void Write(const std::string&) = 0;
	virtual ~Stream() {}

	// �׿ܿ� Read, IsOpen, Flush ���� �پ��� ����� ���� �Լ��� ���
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
	FileStream fs("a.txt");
	fs.Write("AAA");

//	NetworkStream ns("192.168.1.100", 4000);
//	ns.Write("AAA");

}