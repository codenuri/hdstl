// 5_함수객체5-1
#include <iostream>
#include <vector>
#include <algorithm>

/*
bool foo(int n)
{
	return n % k == 0; // error. 여기서 k 는 사용할수 없습니다.
}
*/

class IsDivide
{
	int value;
public:
	IsDivide(int n) : value(n) {}

	bool operator()(int n) // 이함수 때문에 인자가 한개인 함수 처럼 사용가능
	{
		return n % value == 0;
	}
};
int main()
{
	int k = 4;

	std::vector<int> v = { 1,9,3,4,5,6,7,8,9,10 };

	auto ret2 = std::find_if(v.begin(), v.end(), ?);
}
