#include <iostream>
#include <algorithm> 


// sort 함수를 생각해 봅시다.

// sort의 비교 정책은 사용자가 변경할수 있게 하면 좋습니다.
// 그런데..
// 아래 함수는 "비교 정책 변경" 이 가능해서 유연성이 좋지만
// 직접 비교하는 코드에 비해서 너무 느립니다.(2중 루프안에서 함수 호출)
// => 비교 함수는 절대 인라인 치환 될수 없습니다.(함수 포인터에 담아서 호출하므로)
void Sort(int* x, int sz, bool(*cmp)(int, int) )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
		//	if (x[i] > x[j])				// 1

			if ( cmp(x[i], x[j]) == true )	// 2
				std::swap(x[i], x[j]);
		}
	}
}
//------------------------------------
inline bool cmp1(int a, int b) { return a > b; }
inline bool cmp2(int a, int b) { return a < b; }

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Sort(x, 10, &cmp1); // 비교 정책 전달
}

