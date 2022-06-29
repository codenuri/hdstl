#include <iostream>
#include <algorithm> 


// sort 함수를 생각해 봅시다.

// sort의 비교 정책은 사용자가 변경할수 있게 하면 좋습니다.
void Sort(int* x, int sz, bool(*cmp)(int, int) )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
		//	if (x[i] > x[j])  

			if ( cmp(x[i], x[j]) == true )
				std::swap(x[i], x[j]);
		}
	}
}
//------------------------------------
bool cmp1(int a, int b) { return a > b; }
bool cmp2(int a, int b) { return a < b; }

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Sort(x, 10, &cmp1); // 비교 정책 전달
}

