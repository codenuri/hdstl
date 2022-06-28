#include <iostream>
#include <iterator>
#include <list>

int main()
{
	int n = 10;

	std::cout << n << std::endl;


	// stream iterator
	std::ostream_iterator<int> p(std::cout, " ");

	*p = 10; // std::cout << 10 << " " 의 의미.
	++p;     // 이 반복자는 ++ 연산자가 하는일은 없지만, 
			 // 사용해도 에러가 아닙니다.
			 // => std::copy 에 이 반복자를 전달하려면 ++이 되어야 합니다
	*p = 20; 


	std::list<int> s = { 1,2,3 };
	std::copy(s.begin(), s.end(), p);

}