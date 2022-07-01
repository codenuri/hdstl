#include <memory>
#include <iostream>

int main()
{
	// �ڿ��� �����ϴ� ����Ʈ ������
	std::unique_ptr<int> up1(new int);
	std::unique_ptr<int> up2 = up1; // error. �ڿ� ���� �ȵ˴ϴ�.
	std::unique_ptr<int> up3 = std::move(up1); // ok..  �ڿ� �̵��� ����

	// unique_ptr �� ������尡 ���� �����ϴ�.
	// "raw pointer" �� ����ϴ� �Ͱ� ���� �����մϴ�.
	std::cout << sizeof(up1) << std::endl;
}
// std::shared_ptr : �ڿ��� ���� ������ ����Ʈ ������
// std::unique_ptr : �ڿ��� �����ϴ� ����Ʈ ������
// std::weak_ptr   : �ڿ��� �������� ���� ����Ʈ ������
//					(��ȣ ���� ������ ���� �ذ�)