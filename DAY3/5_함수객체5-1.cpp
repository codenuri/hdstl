// 5_�Լ���ü5-1
#include <iostream>
#include <vector>
#include <algorithm>

/*
bool foo(int n)
{
	return n % k == 0; // error. ���⼭ k �� ����Ҽ� �����ϴ�.
}
*/

class IsDivide
{
	int value;
public:
	IsDivide(int n) : value(n) {}

	bool operator()(int n) // ���Լ� ������ ���ڰ� �Ѱ��� �Լ� ó�� ��밡��
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
