#include <iostream>

// Step 2. 검색 구간의 일반화

// => 전체 문자열 뿐 아니라 "부분 문자열"도 검색 가능 
// => 활용도가 넓어진다 => "일반화(generic)" 이라고 표현

// [first, last) 사이의 문자열에서 선형 검색 수행
// => 반 개행 구간(half-open range)
char* strchr(char* first, char* last, int c)
{
	while (first != last && *first != c)
		++first;

	return first == last ? nullptr : first;
}



int main()
{
	char s[] = "abcdefgh";

	char* p = strchr(s, s+4, 'c');

	if (p == 0)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}