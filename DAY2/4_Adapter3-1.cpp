#include <iostream>
#include <list>
#include <vector>
#include <deque>

// ������ ����� Adapter
// => list ��ü�� ����� �ܺο� ���������� �ʰڴٴ� �ǵ�

template<typename T> class stack 
{
//	std::list<T>* c; // �̷��� �����ͳ� ���� ���, �ܺο� �ִ� ��ü�� ����Ų�ٴ� �ǹ�
					 // ����, ��ü �����
	std::list<T> c;  // �̷��� �ϸ� stack ������, list �� ���� ������.
					 // ��, stack �� list �� ����. ���� Ŭ���� �����.
public:
	void push(const T& a) { c.push_back(a); }
	void pop()			  { c.pop_back(); }
	T& top()		      { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
}