// 3_algo4.cpp
#include <list>
#include <vector>
#include "show.h"

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// v�� ��� ��Ҹ� "������" ������

	show(v); // 10,9, 8,7,6,5,4,3,2,1


	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s�� ��� ��Ҹ� "������" ������

	show(v); // 10,9, 8,7,6,5,4,3,2,1
}