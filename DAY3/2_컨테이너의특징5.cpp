#include <list>
#include <vector>

// STL 모든 컨테이너의 공통의 특징

int main()
{
	std::list<int> s = { 1,2,3 };

	// 1. 멤버 타입이 있다.
	std::list<int>::value_type n = s.front(); // int n

	// ? 에 들어갈 최선의 타입은 ?
	unsigned int sz = s.size();
	std::list<int>::size_type sz2 = s.size(); // 이방법이 최선입니다.

	auto sz2 = s.size(); // C++11 부터는 이렇게 



	// 2. 멤버함수는 반환과 제거를 동시에 하지 않는다.
	// => 그래서, 불편하게 생각하는 분들이 많습니다
	// => 그런데, 이렇게 해야지만 가장 안전한 코드를 만들수 있다는
	//    이론이 있습니다.
	int n = s.back();	// 반환만. 제거되지 않는다.
	s.pop_back();		// 제거만 한다. 반환 타입은 void




	// 3. 단위 전략을 많이 사용한다.
	std::list<int, MyAlloc<int>> s2;	// 메모리 할당 방식 변경

	std::set<int, std::greater<int>,   // 비교 정책 변경
				  MyAlloc<int>> ss;	   // 메모리 할당 방식 변경
}



