#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
//	std::vector<int> c1 = { 1,2,3,4,5 };
//	std::vector<int> c2 = { 0,0,0,0,0 };

	std::list<int> c1 = { 1,2,3,4,5 };
	std::list<int> c2 = { 0,0,0,0,0 };

	// c1 의 모든 내용을 c2 에 복사 하기.
	// 그런데, [] 연산자는 vector 는 되는데, list 는 안됩니다.
//	for (int i = 0; i < 5; i++)
//		c2[i] = c1[i];

	// list 의 모든 내용을 복사 하려면
	// 1. 반복자를 꺼내서 복사하는 루프를 만들거나
	// 2. std::copy 알고리즘으로 하세요
	std::copy(c1.begin(), c1.end(), c2.begin()); // vector, list 
												// 모두 가능

}

