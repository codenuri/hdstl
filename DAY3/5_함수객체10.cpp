// 5_�Լ���ü10
#include <iostream>
#include <vector>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// std::sort ��� �ϴ� ���
	// 1. �� ��å�� �������� ������ ���� �������� ����
	std::sort(v.begin(), v.end());

	// 2-1. ����å���� �Ϲ� �Լ� ���
	std::sort(v.begin(), v.end(), cmp1);
}