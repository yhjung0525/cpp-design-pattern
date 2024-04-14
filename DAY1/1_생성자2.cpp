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

class Student : public Person
{
	int id;
public:
	// ����� �ڵ�			  // �����Ϸ��� ������ �ڵ�
//	Student(int n) : id(n) {} // Student(int n) : Person(), id(n) {} 

	// Student �� ����� �����ڴ� Person �� ����Ʈ �����ڰ� ���ٴ� ����
	// �˾ƾ� �ϰ�.
	// �Ʒ� ó�� �����ڸ� ����� �־�� �մϴ�.
	Student(const std::string& name, int age, int n) 
		: Person(name, age), id(n) {}
};

int main()
{
	Student s("kim", 30, 15);

	Person p("kim", 20);

//	Person p1;	// �̷��� ��ü�� ����� �ִٴ� ���� ������� ? (�ʱ�ȭ ���� ���� ��ü)
}


