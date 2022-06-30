#include <iostream>
#include "show.h"

#include <set> // Red Black Tree로 구현

int main()
{
	std::set<int> s;

	s.insert(20);
	s.insert(30);
	s.insert(15);
	s.insert(5);
	s.insert(40);

	// 핵심. STL 사용시 컨테이너의 특징을 잘 생각하고 사용하세요

	// 아래 코드를 평가해 보세요
	// "std::find" : 선형 검색을 수행하는 알고리즘, 
	//				first 를 ++ 하면서 요소 검색
	auto ret = std::find(s.begin(), s.end(), 30);
			// => 에러는 없지만, set 을 사용하는 이유는
			// => 선형 검색이 아닌
			// => 이진 검색을 위해서 입니다.
		
	auto ret2 = s.find(30); // 이진 검색

	std::cout << *ret2 << std::endl;

	// "알고리즘과 동일한 이름의 멤버 함수가 있다면
	//  멤버 함수를 사용해라"


}








