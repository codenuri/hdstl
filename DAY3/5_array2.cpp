#include "show.h"

// 아래 코드 잘생각해 보세요
template<typename T, int N>
struct array
{
	T buff[N];

	int size() const { return N; }
	bool empty() const { return N == 0; }

	// STL 컨테이너가 가져야 하는 규칙을 지켜야 합니다
	using value_type = T ;
	using iterator = T* ;

	iterator begin() { return buff ; } // &buff[0] 동일 합니다.
	iterator end()   { return buff + N ; }
};

int main()
{
	array<int, 5> arr = { 1,2,3,4,5 }; // 이렇게 초기화가 가능합니다
								    // 지역변수 이므로 모든 요소(배열)은 stack에
	// 결국 array 는 "진짜 배열"과 동일한 구조입니다.
	// 그런데, 배열에 없는 멤버 함수가 있습니다.
	std::cout << arr.size() << std::endl;

	// 이제 array 는 다른 STL 컨테이너와 동일하게 사용할수 있습니다.
	auto p1 = arr.begin();

	while (p1 != arr.end())
	{
		std::cout << *p1 << std::endl;
		++p1;
	}
}