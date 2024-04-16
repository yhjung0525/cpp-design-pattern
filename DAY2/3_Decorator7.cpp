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
		printf("%s 쓰기\n", s.c_str());
	}
};
//--------------------------------------

class ZipDecorator : public Stream
{
	Stream* stream; // 외부에 이미 존재하는 다양한 Stream 객체(FileStream, NetworkStream)
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void Write(const std::string& s) override 
	{
		auto s2 = "[ " + s + " 압축됨 ]";	// 추가 기능을 수행하고

		stream->Write(s2);					// Stream 객체에 다시 전달.
	}
};

class EncryptDecorator : public Stream
{
	Stream* stream; 
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	void Write(const std::string& s) override
	{
		auto s2 = "[ " + s + " 암호화됨 ]";	

		stream->Write(s2);					
	}
};


int main()
{
	FileStream fs("a.txt");

	EncryptDecorator ed(&fs);
	ed.Write("AAA");		// 1. 암호화 기능을 수행하고
							// 2. fs.Write()에 전달

	ZipDecorator zd(&ed);
	zd.Write("AAA");		// 1. 압축기능을 수행하고 (추가된 기능)
							// 2. ed.Write()에 전달
}