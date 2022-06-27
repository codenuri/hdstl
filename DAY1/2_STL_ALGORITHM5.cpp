#include <iostream>

// Step 5. 검색 실패시 반환값
// => 검색 실패시 nullptr 이 아닌 last 를 반환
// => last 는 검색 대상이 아니므로 검색 성공시에는 절대 last가 나올수 없다.

// 장점 1. find 구현 자체가 간결해 지고, 빠르다.
// 장점 2. 검색 실패시 반환 값은 다음 검색 구간의 시작이 된다.

template<typename T1, typename T2>
T1 find(T1 first, T1 last, T2 c)
{
	while (first != last && *first != c)
		++first;

	return first;// == last ? nullptr : first;
}



int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	double* p = find(x, x + 3, 5);

	if (p == x+3)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}