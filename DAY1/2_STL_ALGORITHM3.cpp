#include <iostream>

// Step 3. 검색 대상 타입의 일반화
// => char* 대신 "템플릿 사용"
// => 함수 이름 변경 : "strchr" -> "find"

// 모든 타입의 배열에서 [first, last) 사이에서 선형검색수행
template<typename T> 
T* find(T* first, T* last, T c)
{
	while (first != last && *first != c)
		++first;

	return first == last ? nullptr : first;
}

int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	double* p = find(x, x + 10, 5.0);

	if (p == 0)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}