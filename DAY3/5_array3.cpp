#include "show.h"

#include <array> // �� �ȿ� �տ��� ���� array �� ������ �ڵ尡 �ֽ��ϴ�.
				// ����, ��� �Լ��� ǥ�ؿ� ���� ���� �ֽ��ϴ�.
int main()
{
	std::array<int, 5> arr = { 1,2,3,4,5 }; 

	arr[0] = 0; // �ᱹ ���ӵ� �޸� �̹Ƿ� [] ���� �����մϴ�.

	// �Ʒ� �ڵ尡 ����, �������� ������ ������ - �޸� ����(����, ���� ��ġ��)�� �߻����ϼ���
	int n1 = arr.front();
	int n2 = arr.back();

	arr.push_front(10);
	arr.push_back(10);

	arr.resize(10);
		
}