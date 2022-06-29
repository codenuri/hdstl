#include "show.h"

#include <array> // 이 안에 앞에서 만든 array 와 유사한 코드가 있습니다.
				// 물론, 멤버 함수는 표준에 좀더 많이 있습니다.
int main()
{
	std::array<int, 5> arr = { 1,2,3,4,5 }; 

	arr[0] = 0; // 결국 연속된 메모리 이므로 [] 연산 가능합니다.

	// 아래 코드가 될지, 에러일지 예측해 보세요 - 메모리 구조(스택, 힙등 위치도)를 잘생각하세요
	// => 결국 "진짜 배열"과 동일한 구조
	int n1 = arr.front(); // ok
	int n2 = arr.back();  // ok

	// std::array 는 결국 배열 이므로 크기 변경, 삽입, 삭제 모두 안됩니다.
	arr.push_front(10);	// error
	arr.push_back(10);	// error
	arr.resize(10);		// error

	// 어차피 크기 변경도 안되는데, 진짜 배열 사용하지 왜? std::array 사용합니까 ?
	// => 배열에 없는몇가지 편리한 멤버 함수가 있습니다.
	int n3 = arr.size();

	// vector vs array
	// 속도 : array 승!
	// 유연성 : vector 승!. 크기 변경, 삽입 삭제
}