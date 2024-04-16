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
//--------------------------------------

class ZipDecorator : public Stream
{
	Stream* stream; // �ܺο� �̹� �����ϴ� �پ��� Stream ��ü(FileStream, NetworkStream)
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void Write(const std::string& s) override 
	{
		auto s2 = "[ " + s + " ����� ]";	// �߰� ����� �����ϰ�

		stream->Write(s2);					// Stream ��ü�� �ٽ� ����.
	}
};

class EncryptDecorator : public Stream
{
	Stream* stream; 
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	void Write(const std::string& s) override
	{
		auto s2 = "[ " + s + " ��ȣȭ�� ]";	

		stream->Write(s2);					
	}
};


int main()
{
	FileStream fs("a.txt");

	EncryptDecorator ed(&fs);
	ed.Write("AAA");		// 1. ��ȣȭ ����� �����ϰ�
							// 2. fs.Write()�� ����

	ZipDecorator zd(&ed);
	zd.Write("AAA");		// 1. �������� �����ϰ� (�߰��� ���)
							// 2. ed.Write()�� ����
}