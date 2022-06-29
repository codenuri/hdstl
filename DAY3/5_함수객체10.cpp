// 5_함수객체10
#include <iostream>
#include <vector>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// std::sort 사용 하는 방법
	// 1. 비교 정책을 전달하지 않으면 오름 차순으로 정렬
	std::sort(v.begin(), v.end());

	// 2-1. 비교정책으로 일반 함수 사용
	std::sort(v.begin(), v.end(), cmp1);
}