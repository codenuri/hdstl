#include "show.h"

#include <array> // 이 안에 앞에서 만든 array 와 유사한 코드가 있습니다.
				// 물론, 멤버 함수는 표준에 좀더 많이 있습니다.
int main()
{
	std::array<int, 5> arr = { 1,2,3,4,5 }; 

	arr[0] = 0; // 결국 연속된 메모리 이므로 [] 연산 가능합니다.

	// 아래 코드가 될지, 에러일지 예측해 보세요 - 메모리 구조(스택, 힙등 위치도)를 잘생각하세요
	int n1 = arr.front();
	int n2 = arr.back();

	arr.push_front(10);
	arr.push_back(10);

	arr.resize(10);
		
}