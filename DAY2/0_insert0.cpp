#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
//	std::vector<int> c1 = { 1,2,3,4,5 };
//	std::vector<int> c2 = { 0,0,0,0,0 };

	std::list<int> c1 = { 1,2,3,4,5 };
	std::list<int> c2 = { 0,0,0,0,0 };

	// c1 �� ��� ������ c2 �� ���� �ϱ�.
	// �׷���, [] �����ڴ� vector �� �Ǵµ�, list �� �ȵ˴ϴ�.
//	for (int i = 0; i < 5; i++)
//		c2[i] = c1[i];

	// list �� ��� ������ ���� �Ϸ���
	// 1. �ݺ��ڸ� ������ �����ϴ� ������ ����ų�
	// 2. std::copy �˰������� �ϼ���
	std::copy(c1.begin(), c1.end(), c2.begin()); // vector, list 
												// ��� ����

}

