#include <iostream>
#include <list>

int main()
{
	std::list<int> s1 = { 1,2,3 };

	auto p1 = std::begin(s1);	// s1.begin()
	auto p2 = std::end(s1);		// s1.end()
								// "past the end"
	// [p1, p2)
	*p1 = 10; // ok
	*p2 = 10; // runtime error. p2 �� �������� �ƴ� ������ ������ ����Ų��.

	// p2�� p1 �ݺ��ڸ� ++�� �̵���, ���� �����ߴ��� ���� �뵵(==, !=)�θ�
	// ����ؾ� �մϴ�.
	while (p1 != p2)
	{
		std::cout << *p1 << std::endl;
		++p1;
	}
	// 2���� �ݺ��ڿ� ���� == ������ true ��� empty �Դϴ�.
	std::list<int> s3;
	if (s3.empty()) {}
	if (std::begin(s3) == std::end(s3)) {}	
	if (s3.begin() == s3.end()) {} // true
}