// 1_������2.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	Person(const std::string& n, int a) : name(n), age(a) {}
};

// Person ���� �Ļ��� Student ����� ������
// 1. �й�(int id) �� �߰��� ������
// 2. �����ڵ� ����� ������
// 3. main ���� Student ��ü ������ ������.


int main()
{
	Person p("kim", 20);

//	Person p1;	// �̷��� ��ü�� ����� �ִٴ� ���� ������� ? (�ʱ�ȭ ���� ���� ��ü)
}


