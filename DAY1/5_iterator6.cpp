#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	int x[5] = { 1, 2, 3, 4, 5 };
	int y[5] = { 0, 0, 0, 0, 0 };
	
	std::list<int> s2 = { 0,0,0,0,0 };

	// x 배열의 모든 내용을 y 로 복사 하기
	// 1. 루프문 작성
	for (int i = 0; i < 5; i++)
		y[i] = x[i];

	// 2. std::copy() 함수 사용
	std::copy(x, x + 5, y); // 위 for 문과 동일
	std::copy(x, x + 5, s2.begin() );

	for (auto e : s2)
		std::cout << e << std::endl;
}