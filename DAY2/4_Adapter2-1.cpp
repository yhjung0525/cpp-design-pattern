// Decorator �� (��ü) Adapter�� �ڵ尡 ������ ���Դϴ�.
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

// �������� ������ ?
// Decorator : �������̽�(�Լ��̸�)�� ������� ����. ������ �̸��ε�, ��� �߰�
FileStream fs("a.txt");
fs.Write("AAA"); 

ZipDecorator zd(&fs);
zd.Write("AAA");	// ������ �Լ� �ε�, ����� �߰��Ȱ�

// Adapter : ������ ����ε�, �������̽�(�Լ��̸�)�� ����Ȱ�
TextView tv("ABCD");
tv.show();

ObjectAdapter oa(&tv);
oa.draw();	// ���� ����ε�, �Լ� �̸��� �޶�����.!!
