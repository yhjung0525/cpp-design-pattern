// upcasting3.cpp
class Animal 
{
public: 
	int age;
};
class Cat : public Animal 
{
};
class Dog : public Animal
{
public:
	int color;
};

// upcasting Ȱ�� #2. ������ ó���ϴ� �Լ� �����. 
//void NewYear(Dog* pDog)	// ���ڷ� Dog ��ü�� �ްڴٴ� �ǵ�. 
void NewYear(Animal* p)		// ���ڷ� ��� ������ �ްڴٴ� �ǵ�. 
{
	++(p->age); 
	
}
int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
}











