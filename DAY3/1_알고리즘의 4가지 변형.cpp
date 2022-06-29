#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"

// 알고리즘의 4가지 변형 - 94 page

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> v2 = { 0,0,0,0,0,0,0,0,0,0 };

	// 1. 기본형
//	auto p1 = std::remove(v1.begin(), v1.end(), 3);


	// 2. 조건자(predicator) 버전
//	auto p2 = std::remove_if(v1.begin(), v1.end(),
//								[](int n) { return n % 2 == 0; });

	// 3. 복사(copy) 버전
	// A. v1=>v2로 copy 후 에서 v2를 remove 하면 되는데 
	//    왜 remove_copy 만들었나요 ?
	//    => copy 후 remove 하는 것 보다 remove_copy 가 빠릅니다.
	// 
	// B. 반환값 p1은 v2의 반복자
	//    => 아래 코드 실행후 v1 자체는 변화가 없습니다. 
	//    => v2의 어느 위치 까지 복사 되었는지 정보가 반환값으로 나옵니다.
//	auto p1 = std::remove_copy(v1.begin(), v1.end(), v2.begin(),  3);

	// 4. 복사 조건자 버전
	auto p1 = std::remove_copy_if(v1.begin(), v1.end(), v2.begin(), 
						[](int n) { return n % 2 == 0; });
	// p1은 v2의 반복자 이므로 필요 없는 곳을 제거 하려면
	v2.erase( p1, v2.end() );

	show(v1); // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
	show(v2); // 1, 3, 5, 7, 9
}
