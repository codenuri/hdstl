#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <algorithm>

int main()
{
	std::vector<int> c = { 1,2,3,4,5,6,7,8,9,10 };

	auto ret = std::find(c.begin(), c.end(), 6);

	// ret �� 6�� ����Ű�� �ݺ��� �Դϴ�.
	// �׷���, ret �� ���° ������� �˼� ������� ?

	std::cout << ret - c.begin() << std::endl;
}

