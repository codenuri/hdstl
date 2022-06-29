// ���� ������ DAY3.zip ���� Ǯ�� ���� �ּ���.
// �Լ���ü5 ~ �Լ���ü10 ������ "������Ʈ���� ����" ���ּ���.

// �Լ���ü 12.cpp
#include <iostream>
#include <functional> // C++ ǥ�� �Լ���ü
#include <algorithm>  
#include <vector>
#include "show.h"

bool cmp1(int a, int b) { return a < b; }
int main()
{
	std::vector<int> v = { 1,3,5,7, -9 ,2,4,6,8,10 }; // 9 �� ����

	// sort ���
	// 1. ���� �������� �ϰ� �ʹ�. - �� ��å �������� �ʾƵ� �˴ϴ�.
	std::sort(v.begin(), v.end());
	show(v);

	// 2. ���� �������� �ϰ� �ʹ�. - std::greater<int> �����ϼ���
	std::sort(v.begin(), v.end(), std::greater<int>() );
	show(v);

	// 3. ���밪 ���� �������� �ϰ� �ʹ�. 
	// => ǥ�ؿ� ���밪���� ���ϴ�  �Լ� ��ü�� �����ϴ�. 
	// => ����ڰ� ������ �մϴ�.
	// => 1. Ŭ������ ���� �����
	// => 2. ���� ǥ�������� �����Ϸ����� ��û�ϱ�.
	std::sort(v.begin(), v.end(), 
					[](int a, int b) { return abs(a) < abs(b); });
	show(v);

	// 4. ����Ÿ ���� ���ų�, 
	//    �ӵ� ���ٴ� �޸� ��뷮�� �߿��� ȯ���̶��
	//    "����ǥ�����̳� �Լ���ü" ���ٴ� "�Ϲ��Լ�(������)"�� �� ��å���� ���
	std::sort(v.begin(), v.end(), cmp1); 
	show(cmp1);
}

