// ���� ������ DAY3.zip ���� Ǯ�� ���� �ּ���.
// �Լ���ü5 ~ �Լ���ü10 ������ "������Ʈ���� ����" ���ּ���.

// �Լ���ü 12.cpp
#include <iostream>
#include <functional> // C++ ǥ�� �Լ���ü
#include <algorithm>  
#include <vector>
#include "show.h"

int main()
{
	std::vector<int> v = { 1,3,5,7, -9 ,2,4,6,8,10 }; // 9 �� ����

	// sort ���
	// 1. ���� �������� �ϰ� �ʹ�.
	std::sort(v.begin(), v.end());
	show(v);
}