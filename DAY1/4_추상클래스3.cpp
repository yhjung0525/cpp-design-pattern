//1_�߻�Ŭ����2.cpp
#include <iostream>

// ���� ����(tightly coupling)
// => �ϳ��� Ŭ������ �ٸ� Ŭ���� ����, Ŭ���� �̸��� ���� ����ϴ� ��
// => ��ü �Ұ�����, ������ ������


// ���� ����(loosely coupling)
// => �ϳ��� Ŭ������ �ٸ� Ŭ���� ����, 
//    ��Ģ�� ���� �������̽�(�߻�Ŭ����)�� �̿��ؼ� ����ϴ� ��.
// => ��ü ������, ������ ������

// �������̽� : ��Ģ(���������Լ�) �� ������ �ִ°�
// �߻�Ŭ���� : ��Ģ(���������Լ�) + �ٸ� ����� ���� ���. 

// java, C# �� "interface" , "abstract" ��� Ű���� ����
// C++�� ��� "�߻�Ŭ���� ����" ���� �� �ۼ�. 


//=================================================================
// ī�޶� ������ �� ī�޶� ����ڰ� ���Ѿ� �ϴ� ��Ģ�� ���� ���� �մϴ�.
// ��Ģ : "��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ� �Ǿ�� �Ѵ�." ��� ǥ������ ����
// ��Ģ : "��� ī�޶�� �Ʒ� �������̽��� �����ؾ� �Ѵ�." ��� ǥ���մϴ�.

// �������̽� ���鶧, "class" �� ����ص� �ƹ� ���� ������
// "struct" �� �ϴ� ��찡 �����ϴ�.(public ������ ǥ���� �ʿ� �����Ƿ�)

#define interface struct

//interface ICamera
struct ICamera
{
	virtual void take() = 0;
	virtual ~ICamera() {}   // �������̽��� �ᱹ ��� Ŭ���� �Դϴ�.
							// �ݵ�� �Ҹ��ڸ� �����Լ��� �ؾ� �մϴ�.
};





// ���� ī�޶� ����ڴ� "��Ģ" ��θ� ����ؾ� �մϴ�.
// ���� ī�޶� ���, ��Ģ �� �˰� �ڵ带 �ۼ��Ҽ� �ֽ��ϴ�.
class People
{
public:
	void use_camera(ICamera* c) { c->take(); }
};

// ��� ī�޶� �����ڴ� "��Ģ"�� ���Ѿ� �մϴ�.
class Camera : public ICamera
{
public:
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); 

	UHDCamera uhc;
	p.use_camera(&uhc); // ok.. ���߿� �߰��� Ŭ������
						// People �ڵ� �������� ��밡��

}



