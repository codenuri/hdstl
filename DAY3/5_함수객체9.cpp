// 3_�Լ���ü7 - 136 page�ҽ�
#include <iostream>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less   { inline bool operator()(int a, int b) { return a < b; }};
struct Greater{	inline bool operator()(int a, int b) { return a > b; }};

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// C++ ǥ�� sort()�� ��� ���ڰ� ���ø� �Դϴ�.
	// => ����ڰ� ����ϴ� �ڵ带 ���� ���� sort �Լ��� �����ȴٴ� �ǹ�
	// 
	// 1. �� ��å���� �Ϲ��Լ� ����
	
	// ���� : ����å�� ������ ��ü�ص�, �����Ǵ� sort() �Լ��� �Ѱ� �̴�.
	//       �ڵ� �޸� ���� ����.

	// ���� : �� ��å �Լ�(cmp1, cmp2)�� ������ ġȯ �ɼ��� ����.
	//       ������.
	//       Ư��, sort �Ϸ��� ����� ������ ���ٸ� �������ϰ� ũ��.

	std::sort(x, x+10, cmp1); // sort(int*, int*, bool(*)(int, int)) ������Լ�����
	std::sort(x, x+10, cmp2); // sort(int*, int*, bool(*)(int, int)) ������Լ�����


	// 2. ����å���� �Լ���ü ����

	// ���� : �� ��å�� �ζ��� ġȯ �ɼ� �ִ�. ������...
	// ���� : �� ��å�� ��ü�� Ƚ�� ��ŭ�� sort ���� �ڵ尡 �����ȴ�.
	//       �ڵ� �޸𸮰� �����Ҽ� �ִ�.

	Less    f1;
	Greater f2;
	std::sort(x, x+10, f1); // sort( int*, int*,  Less  ) ����� �Լ��� ����
	std::sort(x, x+10, f2); // sort( int*, int*,  Greater  ) ����� �Լ��� ����
}









