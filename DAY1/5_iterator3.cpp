#include <iostream>
#include <list>   
#include <vector>

int main()
{
//	std::list<int>   s = { 1,2,3,4,5 };
//	std::vector<int> s = { 1,2,3,4,5 };
	int s[5] = { 1,2,3,4,5 };

	// �ݺ��ڸ� ������ ��
	// C++98 ��Ÿ��
	// 1. �º��� Ÿ���� ������ ���δ�.
	// 2. �����̳� ����� �º��� �ݺ��� Ÿ�� �ڵ嵵 �����Ǿ�� �Ѵ�.
//	std::list<int>::iterator p = s.begin();

	// C++11 ��Ÿ�� - auto ���
//	auto p = s.begin(); // s�� "raw array" �� ���� ����

	auto p = std::begin(s); // s �� �����̳��̾ ok
							// s �� raw array �� ok
						// raw array �� ���. p �� int* �Դϴ�.

	// C++20 ���ʹ� �ݺ��ڸ� ������ ���ο� ����� ���ɴϴ�.
	auto p2 = std::ranges::begin(s); // ���� �����ϰ� 
									// ���� �����Դϴ�.
}



