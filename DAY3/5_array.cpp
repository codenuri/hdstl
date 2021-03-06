#include <vector>
#include <algorithm>
#include "show.h"

int main()
{
	// 배열 vs vector
	// 공통점 : 연속된 메모리 사용, [] 연산자로 요소 접근
	// 차이점 : 배열    - 크기 변경 안됨. 멤버 함수 없음
	//					stack 에 생성됨. 
	//					원할때 파괴할수 없음, 선언된 블럭을 벗어날때 파괴
	// 
	//         vector - 크기 변경 가능, 몇가지 멤버 함수들
	//					v 객체 자체는 스택에 있지만 모든 요소는 힙을 할당해서 관리
	//                  원할때 파괴, 재할당 가능.
	//					그래서 resize가 가능한 것

	int x[10] = { 1,2,3,4,5,6,7,8,9,10 }; 

	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 }; 

	x[0] = 10;
	v[0] = 10;
}
