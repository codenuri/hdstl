#include <iostream>
#include <vector>
#include <algorithm>

// ������(predicator) : ��ȯ Ÿ���� bool �� �Լ�

// �Ʒ��� ���� �Լ��� ���� "���� ������" ��� ���� �θ��ϴ�.
bool foo(int n)
{
	return n % 3 == 0;
}

int main()
{
	std::vector<int> v = { 1,9,3,4,5,6,7,8,9,10 };

	// �־��� �������� 3�� ã�� �ʹ�.
	auto ret1 = std::find(v.begin(), v.end(), 3);


	// �־��� �������� "3�� ���"�� ã�� �ʹ�.
	// 
	// std::find    : ��   �˻�. 3��° ���ڷ� "��" ����
	// std::find_if : ���� �˻�. 3��° ���ڷ� "�Լ�" ����

	auto ret2 = std::find_if(v.begin(), v.end(), foo );

}