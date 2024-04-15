// 2_�����Լ�������
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// 1. ��� Ŭ���� �����Լ��� override �Ҷ� 
	// => "virtual" �� �־ �ǰ� ��� �˴ϴ�.
	// => ǥ������ �ʾƵ� �ڵ����� virtual 
//	virtual void foo() {}

	// 2. �����Լ� override �ÿ� �Ǽ�(��Ÿ)�� �־
	// => ������ ������ �ƴ϶�!
	// => ���ο� �����Լ��� ���� ������ �����Ϸ��� �����մϴ�.
//	virtual void fooo() {}
//	virtual void goo(double){}

	// 3. 2�������� ���װ� ���� ���ҽ��ϴ�.
	// => �׷���, C++11 ���� "override" Ű���� �߰�
	// => ��Ÿ ���� �Ǽ��� ������ ������ ���� �߻�
	// => override �� ���̴� ���� "virtual" �� ��� �������� ������ �ʽ��ϴ�.!
	void fooo()      override {}
	void goo(double) override {}

};


int main()
{
}





