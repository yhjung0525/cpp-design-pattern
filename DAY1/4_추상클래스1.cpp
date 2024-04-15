// 1_�߻�Ŭ����1.cpp - 10page

// �߻� Ŭ���� : ���� �����Լ��� �Ѱ� �̻� �ִ� Ŭ����
// Ư¡ : ��ü�� �����Ҽ� ����, ��, ������ ������ ����� �ִ�.
class Shape
{
public:
	virtual void draw() = 0; // ���� �����Լ�(pure virtual function)
							 // Ư¡ : �����ΰ� ����, "=0" ���� ǥ��
							 
};
class Rect : public Shape
{
	// draw() �� ������ �������� ������ Rect �� �߻�(abstract)�̴�.
	// draw() �� ������ �����ϸ� Rect �� �߻��� �ƴϴ�.(��ü, concrete type)
public:
	void draw() override {}
};

int main()
{
//	Shape  s; // error
	Shape* p; // ok
	Rect  r;  // ok
}
