
#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

int main()
{
	// 1. ����
	std::vector<int> v1;		// �ʱ� ũ��� ����.
	std::vector<int> v2(10);	// 10���� 0���� �ʱ�ȭ
	std::vector<int> v3(10, 3);	// 10���� 3���� �ʱ�ȭ
	std::vector<int> v4(v3);	// v3�� �����ϰ�..

	std::vector<int> v5 = { 1,2,3 }; // 3���� 1, 2, 3���� �ʱ�ȭ
//	std::vector<int> v5 { 1,2,3 };	 // �� �ڵ�� �� �ڵ�� �����մϴ�.

	// �Ʒ� 2�� ������ �� ����ϼ���
	std::vector<int> v6( 10, 3 ); // 10���� 3���� �ʱ�ȭ
	std::vector<int> v7{ 10, 3 }; // 2���� "10, 3"���� �ʱ�ȭ

	std::cout << v6.size() << std::endl; // 10
	std::cout << v7.size() << std::endl; // 2

	// ���� ��� �ڵ�� list, deque �� �����մϴ�.

	// 2. ����, 




	// 3. ����
	
	// 4. ��� ����

}