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
   
int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	take_view tv(v, 3); // C++17 ���ʹ� ���ø� ���� ��������

//	for (auto e : v)
	for (auto e : tv)
	{
		std::cout << e << std::endl;
	}



}

