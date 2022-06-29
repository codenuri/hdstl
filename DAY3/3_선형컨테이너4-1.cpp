// 3_���������̳�4-1
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include "show.h"

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::list<int>   s1 = { 1,2,3,4,5 };

	// 1. �����̳� ������ ���� Ÿ���� �����̳ʷ� �����ؼ� ����� �ֽ��ϴ�.
	std::vector<int> v2(v1); // ok  v2 = v1;

	// 2. �����̳��� ������ �ٸ��� �Ʒ� ó�� �ݺ��ڷ� �ϼ���
//	std::vector<int> v3(s1); // error
	std::vector<int> v4(s1.begin(), s1.end()); // ok


	// 3. ������ �ƴ� ���� �Ҷ�
	v2 = v1; // v1�� ��� ��Ұ� v2�� "deep copy"

//	v2 = s1; // error. �����̳��� ������ �ٸ���

	std::copy(s1.begin(), s1.end(), v2.begin()); // ok

	
}