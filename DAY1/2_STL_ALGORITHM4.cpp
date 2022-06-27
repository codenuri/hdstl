#include <iostream>

// Step 4. 보다 일반화 되도록

// 템플릿을 아래처럼 만들면 몇가지 문제가 있습니다.

//template<typename T> T* find(T* first, T* last, T c)
// 
// 1. 검색 구간의 타입과 검색요소의 타입이 연관됩니다.
//    => double[] 에서 int 또는 float 등을 찾을수 없습니다.

// 2. 검색 구간을 T* 라고 하면 반드시 "raw pointer" 만 사용가능합니다.
//    => 스마트 포인터 등을 사용할수 없습니다.

template<typename T1, typename T2>
T1 find(T1 first, T1 last, T2 c)
{
	while (first != last && *first != c)
		++first;

	return first == last ? nullptr : first;
}

int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	double* p = find(x, x + 10, 5);


	if (p == 0)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}