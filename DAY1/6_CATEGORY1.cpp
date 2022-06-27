// 53 page ~
#include <forward_list> // 싱글리스트
#include <list>			// 더블리스트

int main()
{
	std::forward_list<int> s1 = { 1,2,3 };

	std::list<int> s2 = { 1,2,3 };

	auto p1 = s1.begin();
	auto p2 = s2.begin();
	
	// 다음중 에러를 찾아 보세요.
	++p1; // ok
	--p1; // error. 싱글리스트는 한쪽 방향으로만 이동 가능하다.
	++p2; // ok
	--p2; // ok

}