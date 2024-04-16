// Decorator 와 (객체) Adapter의 코드가 유사해 보입니다.
class ZipDecorator : public Stream
{
	Stream* stream; 
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void Write(const std::string& s) override { .... } 
};
class ObjectAdapter : public Shape
{
	TextView* tview;  
public:
	ObjectAdapter(TextView* v) : tview(v) {}

	void draw() override  { tview->show(); }
};

// 차이점이 뭔가요 ?
// Decorator : 인터페이스(함수이름)이 변경되지 않음. 동일한 이름인데, 기능 추가
FileStream fs("a.txt");
fs.Write("AAA"); 

ZipDecorator zd(&fs);
zd.Write("AAA");	// 동일한 함수 인데, 기능이 추가된것

// Adapter : 동일한 기능인데, 인터페이스(함수이름)이 변경된것
TextView tv("ABCD");
tv.show();

ObjectAdapter oa(&tv);
oa.draw();	// 동일 기능인데, 함수 이름이 달라졌다.!!
