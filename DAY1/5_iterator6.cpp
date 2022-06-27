#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	int x[5] = { 1, 2, 3, 4, 5 };
	int y[5] = { 0, 0, 0, 0, 0 };
	
	std::list<int> s2 = { 0,0,0,0,0 };

	// x �迭�� ��� ������ y �� ���� �ϱ�
	// 1. ������ �ۼ�
	for (int i = 0; i < 5; i++)
		y[i] = x[i];

	// 2. std::copy() �Լ� ���
	std::copy(x, x + 5, y); // �� for ���� ����
	std::copy(x, x + 5, s2.begin() );

	for (auto e : s2)
		std::cout << e << std::endl;
}