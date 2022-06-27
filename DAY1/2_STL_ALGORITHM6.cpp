#include <iostream>

// find ����

// �ϴ��� : ���� Ÿ���� �迭�� [first, last) �������� �����˻� ����

// ������ Ÿ�� : �ݵ�� ������ �� �ʿ�� ����. 
//				��, !=, ==, *, ++ ������ �����ؾ� �Ѵ�.
// 
// ������ �̵� : ������ ++ ( ++first)
// ������ ���� : last 

// <algorithm> �̶�� ǥ�� ����� �̹� �Ʒ��� ���� find �� �ֽ��ϴ�.

template<typename T1, typename T2>
T1 find(T1 first, T1 last, T2 c)
{
	while (first != last && *first != c)
		++first;

	return first;
}



int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };

//	double* p = find(x, x + 3, 5);
//	double* p = find(x, x + �迭��ũ��, 5);
//	double* p = find(x, x + sizeof(x) / sizeof(x[0]), 5);
	double* p = find(x, x + std::size(x), 5); // �̷��� �ص� �˴ϴ�.
											// �� ���� ����� �ִµ�..
											// ���Ŀ� �����ϰڽ��ϴ�

	if (p == x + 3)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}