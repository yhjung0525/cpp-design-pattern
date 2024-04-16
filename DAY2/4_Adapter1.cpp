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
// ���� �����⿡�� "���ڿ�" �� �����ϰ� �ʹ�.!
// => ���������⿡�� ���� ���� ������ �ִ� "TextView" �� ����Ҽ� ������ ?
// => ���� ����Ҽ��� ����. �������̽� ����ġ(draw() �� �ʿ��ѵ�, show() ����)

// �������̽��� ����ġ�� �ذ��� ����.

class Text : public Shape,		// ������������ �䱸 ����
			 public TextView	// ���� Ŭ������ ��� ����� ���� �޴´�.
{
public:
	Text(const std::string& s) : TextView(s) {}

	// �Ʒ� �ڵ尡 "show ��� �̸��� draw ��� �̸����� ����" �ϴ� �ڵ� �Դϴ�.
	// �������̽��� ����ġ�� �ذ��ϴ� �Լ�!!!
	void draw() override
	{
		TextView::show();
	}
};
int main()
{
	std::vector<Shape*> v;

	v.push_back(new Text("hello"));

	v[0]->draw();
}







