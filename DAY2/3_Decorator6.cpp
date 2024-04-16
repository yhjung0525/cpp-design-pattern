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

int main()
{
//	FileStream fs("a.txt");
//	fs.Write("AAA");

	// 파일에 쓸때 암호화 해서 쓰는 기능이 필요 하다.

	// 방법 1. 데이타를 직접 암호화 한후에 Write() 함수에 전달.

	// 방법 2. FileStream 으로 부터 파생된 클래스를 만든후에
	//         EncryptWrite() 등의 메소드 추가
	// => FileStream 뿐 아니라 NetworkStream 등의 모든 클래스의 파생 클래스 필요
	// => 암호화 뿐 아니라 압축등의 기능이 필요하면 파생 클래스가 계속 늘어나고
	//    2개 기능의 중첩이 어려워 진다

	// 방법 3. Decorator 패턴의 활용
	
	FileStream fs("a.txt");

	EncryptDecorator ed(&fs);
	ed.Write("AAA");		// 1. 암호화 기능을 수행하고
							// 2. fs.Write()에 전달

	ZipDecorator zd(&ed);
	zd.Write("AAA");		// 1. 압축기능을 수행하고 (추가된 기능)
							// 2. ed.Write()에 전달
}