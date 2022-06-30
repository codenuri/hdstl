#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <algorithm>

int main()
{
//	std::vector<int> c = { 1,2,3,4,5,6,7,8,9,10 };
//	std::list<int>  c = { 1,2,3,4,5,6,7,8,9,10 };
	std::set<int>  c = { 1,2,3,4,5,6,7,8,9,10 };

	auto ret = std::find(c.begin(), c.end(), 6);

	// ret �� 6�� ����Ű�� �ݺ��� �Դϴ�.
	// �ݺ��ڴ� ������ ó�� �����Ҽ� �ֽ��ϴ�. ( - ���� ����, �� �������ٸ� )
	// �׷���, ret �� ���° ������� �˼� ������� ?

//	std::cout << ret - c.begin() << std::endl; // �������� �ݺ��ڸ�����
									// vector�� deque

	// �� �ݺ����� ���̸� ���ϴ� �Լ� - ���� ���� �ݺ��ڰ� �ƴ϶� ����
	int n = std::distance(c.begin(), ret); 

	std::cout << n << std::endl;
}

