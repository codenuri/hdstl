// insert2.cpp
#include <iostream>
#include <algorithm>
#include <list>

// 함수 버전

int main()
{
	std::list<int> s1 = { 10,20,30,40,50 };
	std::list<int> s2 = { 1, 2, 3, 4, 5 };
	

	// 아래 코드는 s1 의 내용을 s2 에 덮어쓰는 코드
//	std::copy(s1.begin(), s1.end(), s2.begin());


	// s1의 내용을 s2에 덮어쓰지 말고, 끝에 추가해 봅시다.
	// 1. 코드로 직접 작성한다면..
//	for (int i = 0; i < s1.size(); i++)
//	{
//		s2.push_back( s1[i] ); // 그런데, 이렇게 하면 [] 연산이 필요합니다
							   // vector 는 가능한데, list는 안됩니다.
//	}

	// 2. C++11 의 range-for 사용
//	for (auto e : s1)
//	{
//		s2.push_back(e); // ok.. 
//	}

	// 3. 삽입 반복자와 std::copy 알고리즘 사용
//	std::back_insert_iterator< std::list<int> > p(s2);
//	std::copy(s1.begin(), s1.end(), p);

	// 4. 삽입 반복자를 만들어 주는 함수 사용
	// => 아래 한줄은 위 2줄과 동일합니다
	std::copy(s1.begin(), s1.end(), std::back_inserter(s2));

	for (auto& n : s2)
		std::cout << n << std::endl; 

	// 핵심. 아래 2줄의 차이점을 명확히 알아 두세요
	std::copy(s1.begin(), s1.end(), s2.begin());	// s2에 덮어쓰기
	std::copy(s1.begin(), s1.end(), std::back_inserter(s2)); // s2뒤에 추가
}
