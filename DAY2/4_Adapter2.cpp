#include <iostream>
#include <string>
#include <vector>

// �Ʒ� Ŭ������ �̹� �־��ٰ� ������ ���ô�.
// => ���ڿ��� ȭ�鿡 �̻ڰ� ����ϴ� Ŭ����..
// => �������� ������ �ִ� Ŭ������� ����.
class TextView
{
	std::string data;
	// font color, size, bold, 
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};
//========================================================

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};
//==========================================

// Ŭ���� ����� : Ŭ������ �������̽� ����
// ��ü   ����� : ��ü��   �������̽� ����

class Text : public Shape, public TextView	
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() override
	{
		TextView::show();
	}
};

// �Ʒ� Ŭ������ ��ü �����
class ObjectAdapter : public Shape
{
	TextView* tview;  // �ٽ� : ������ �Ǵ� ������ ����� ��� 
					  // => �ܺο��� ������ ��ü�� ����Ű�ڴٴ� �ǵ�.
public:
	ObjectAdapter(TextView* v) : tview(v) {}

	// ���� ������ �ý����� �䱸 ����!!
	// => TextView �� show �� draw �̸����� ��밡���ϰ�
	// => Ŭ����(TextView)�� �ƴ� ��ü(tview�� ����Ű��) �� �������̽� ����
	void draw() override
	{
		tview->show();
	}
};




int main()
{
	std::vector<Shape*> v;

	TextView tv("ABCD"); // TextView : Ŭ����
						 // tv       : ��ü
						  
	// �̹� ������ ��ü�� tv �� v�� ������ ������� ?
	// ������ ���� Text �� ����ؼ��� tv ��ü�� v�� �������� �����ϴ�.
	// Text �� "Ŭ���� �����" �̹Ƿ� 
	// 
//	v.push_back( &tv ); // error. tv �� Shape �� ���� ��ӹ��� �ʾҴ�

	v.push_back( new ObjectAdapter(&tv) ); // ��ġ ���� ���� �������̽���
										   // ����͸� ���ؼ� �ذ�
								// 220v �� 110v �� �����ϱ� ���� "������(����)" �� �����
											

}







