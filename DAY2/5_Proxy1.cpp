// �ǽ��� ���ô� ���� 
// 1. visual studio �Ѱ��� �������ϼ���
// 2. server.zip ���� Ǯ��, ���ο� vs ���� ���� ������
// 3. vs���� 32bit ȯ�濡���� ���� �����մϴ�.

#define USING_GUI
#include "cppmaster.h"

// Step1. C ��Ÿ��!
// ���� �ڵ��� ����
// 1. ��� Ŭ���̾�Ʈ �����ڰ� IPC ����� �˾ƾ� �Ѵ�.
// 2. server/client ����� 1, 2 ��� ����(����ڵ�)�� �ܿ��� �Ѵ�.


int main()
{
	// 1. ������ �ڵ��� ��� �ɴϴ�.
	int server = ec_find_server("Calc");

	std::cout << "���� ��ȣ : " << server << std::endl;

	// 2. ������ ����ڵ�� �Ķ���͸� �����մϴ�.
	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





