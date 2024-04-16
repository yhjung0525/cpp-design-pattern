#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// 다양한 Stream 클래스의 공통의 인터페이스 설계
struct Stream
{
	virtual void Write(const std::string&) = 0;
	virtual ~Stream() {}

	// 그외에 Read, IsOpen, Flush 등의 다양한 입출력 관련 함수를 약속
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

int main()
{
	FileStream fs("a.txt");
	fs.Write("AAA");

//	NetworkStream ns("192.168.1.100", 4000);
//	ns.Write("AAA");

}