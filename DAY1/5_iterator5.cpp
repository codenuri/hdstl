#include <iostream>
#include <list>

int main()
{
	std::list<int> s1 = { 1,2,3 };

	auto p1 = std::begin(s1);	// s1.begin()
	auto p2 = std::end(s1);		// s1.end()
								// "past the end"
	// [p1, p2)
	*p1 = 10; // ok
	*p2 = 10; // runtime error. p2 는 마지막이 아닌 마지막 다음을 가리킨다.

	// p2는 p1 반복자를 ++로 이동후, 끝에 도달했는지 비교의 용도(==, !=)로만
	// 사용해야 합니다.
	while (p1 != p2)
	{
		std::cout << *p1 << std::endl;
		++p1;
	}
	// 2개의 반복자에 대한 == 연산이 true 라면 empty 입니다.
	std::list<int> s3;
	if (s3.empty()) {}
	if (std::begin(s3) == std::end(s3)) {}	
	if (s3.begin() == s3.end()) {} // true
}