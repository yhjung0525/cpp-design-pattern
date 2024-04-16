#include <memory>

int main()
{
	// C++ ǥ�ؿ� �̹� ����Ʈ ������ "std::shared_ptr" �� �ִµ�
	// �̰��� ����ϸ� �ȵǳ��� ?

	std::shared_ptr<ICalc> sp1( reload_proxy() );
				// => proxy �ּҸ� �����ϰ� �ִٰ�
				// => sp1 �� �ı��ɶ� �Ҹ��ڿ��� delete �ϰ� �˴ϴ�.
				// => �츮�� ���ϴ� ���� "delete" �� �ƴ϶�
				//    Release()�� ȣ���ؼ� DLL ���ο��� delete �� �ϰ� ������!!!
	
	sp<ICalc> sp2 = reload_proxy();
				// => �����ڿ��� "AddRef" ȣ��
				// => �Ҹ��ڿ��� "Release" ȣ��
				// => delete �� DLL ���ο���!!

	// �׷��� C++ ǥ�ؿ� ����Ʈ �����Ͱ� ������,
	// ���� ���¼ҽ����� �ٽ� �ڽŵ鸸�� ����Ʈ �����͸� �����մϴ�.
}