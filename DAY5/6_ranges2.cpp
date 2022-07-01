#include <iostream>
#include <vector>
#include <algorithm>

template<typename T> 
class take_view
{
	T& r;
	int count;
public:
	take_view(T& c, int n) : r(c), count(n) {}

	auto begin() { return r.begin(); }
	auto end()   { return r.begin() + count; }
};
template<typename T>
class reverse_view
{
	T& r;
public:
	reverse_view(T& c) : r(c) {}
	auto begin() { return r.rbegin(); }
	auto end()   { return r.rend(); }
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

//	take_view tv(v, 3); // C++17 부터는 템플릿 인자 생략가능
	reverse_view rv(v);

//	for (auto e : v)
//	for (auto e : tv)
//	for (auto e : rv)
	for (auto e : reverse_view(v) )
	{
		std::cout << e << std::endl;
	}



}

