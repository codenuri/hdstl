#include <iostream>
#include <list>
#include <vector>

template<typename T>
typename T::value_type sum(T first, T last)
{
	// value_type �� �����̿� �ݺ��ڿ� ��� �ֽ��ϴ�.
	// std::list<int>::value_type           : list �� �����ϴ� ����� Ÿ��
	// std::list<int>::iterator::value_type : �ݺ��ڰ� ����Ű�� ����� Ÿ��
	// 
	// T				: �ݺ��� Ÿ�� ( std::list<int>::iterator )
	// T::value_type	: �ݺ��ڰ� ����Ű�� ����� Ÿ��
	typename T::value_type s = 0;

	while (first != last)
	{
		s = s + *first;
		++first;
	}
	return s;
}

int main()
{
//	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	int n = sum( std::begin(s), std::end(s) );

	std::cout << n << std::endl; // 55
}