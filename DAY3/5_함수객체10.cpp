// 5_�Լ���ü10
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // C++98 ���� �����Ǵ� C++ ǥ�� �Լ� ��ü��
inline bool cmp1(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// std::sort ��� �ϴ� ���
	// 1. �� ��å�� �������� ������ ���� �������� ����
	std::sort( v.begin(), v.end() );     

	// 2-1. ����å���� �Ϲ� �Լ� ���
	std::sort(v.begin(), v.end(), cmp1); // 2�� ��� �񱳽� cmp1 �� ����ϴµ�
										// cmp1 �� �ζ��� ġȯ�� ������ �ʽ��ϴ�.
										// ��, ����~����� cmp1 �� ȣ��˴ϴ�.

	// 2-2. �� ��å���� �Լ� ��ü�� ����ϴ� ���
	std::less<int> f;	// �̹� C++ǥ��(C++98) �� ���� �Լ� ��ü�� �ֽ��ϴ�.
						// "a < b" �� �����ϴ� ���� �Լ���ü - 87page
	std::sort(v.begin(), v.end(), f);

	// less �� ������ ����Ѵٸ�,, ��ó�� ����� ����ϼ���..
	// �׷���, �ѹ��� ����ϸ� �Ʒ� ó�� �ӽð�ü���·� ����ϴ� ��찡 �����ϴ�
	std::sort(v.begin(), v.end(), std::less<int>() );
}