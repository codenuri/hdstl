#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main()
{
//	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = std::begin(s);

	// �ݺ��� p�� 5ĭ �����ϰ� �ʹ�. �ּ��� �ڵ�� ???
//	p = p + 5;		// ���� ���� �ݺ��ڸ� ������ �ڵ�
					// list �� �ݺ��ڶ�� error
//	++p; ++p; ++p; ++p; ++p; // ��� �ݺ��ڴ� ++�� �ȴ�.
							 // ��� �����̳ʿ� ��밡��
							 // ������, p�� ���������̸� ������.!!

	std::advance(p, 5); // �ּ��� �ڵ�

	sdt::cout << *p << std::endl;
}