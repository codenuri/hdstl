// 1_STL_PREVIEW1
#include <iostream>
#include <list>		// ���� ��ũ�� ����Ʈ
#include <vector>

int main()
{
	std::list<int> s = { 1,2,3,4,5 }; // ������ �ʱ�ȭ ����

	s.push_back(10);
	s.push_front(20);

	std::vector<int> v = { 1,2,3,4,5 }; // ��� ��Ұ� ���ӵ� �޸�
	v[0] = 10; // �迭 ó�� [] ��뵵 ����.
}