#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n)
{
	return n % 3 == 0;
}

int main()
{
	std::vector<int> v = { 1,9,3,4,5,6,7,8,9,10 };

	// �־��� �������� "3�� ���"�� ã�ƶ�!
	auto ret1 = std::find_if(v.begin(), v.end(), foo);

	// �ٽ� : �Ʒ� �ڵ� ���� �� ������
	int k = 0;
	std::cin >> k;

	// �־��� �������� "k�� ���"�� ã�ƶ�!!
	// => ? �� ä�� ������.. 
	auto ret2 = std::find_if(v.begin(), v.end(), ?);
}