// 3_선형컨테이너4-1
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include "show.h"

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::list<int>   s1 = { 1,2,3,4,5 };

	// 1. 컨테이너 생성시 동일 타입의 컨테이너로 복사해서 만들수 있습니다.
	std::vector<int> v2(v1); // ok  v2 = v1;

	// 2. 컨테이너의 종류가 다르면 아래 처럼 반복자로 하세요
//	std::vector<int> v3(s1); // error
	std::vector<int> v4(s1.begin(), s1.end()); // ok


	// 3. 생성이 아닌 대입 할때
	v2 = v1; // v1의 모든 요소가 v2에 "deep copy"

//	v2 = s1; // error. 컨테이너의 종류가 다를때

	std::copy(s1.begin(), s1.end(), v2.begin()); // ok

	
}