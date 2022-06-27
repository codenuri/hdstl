#include <iostream>
#include <vector>
#include <list>

/*
void print_first_element(std::vector<int>& v)
{
	int n = v.front();

	std::cout << n << std::endl;
}
*/

/*
template<typename T>
void print_first_element(std::vector<T>& v)
{
	T n = v.front();

	std::cout << n << std::endl;
}
*/
template<typename T>
void print_first_element(T& v)
{
	// T : std::list<double>
	? n = v.front();

	std::cout << n << std::endl;
}


int main()
{
//	std::vector<int>    v = { 1,2,3,4,5,6,7,8,9,10 };
//	std::vector<double> v = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<double>   v = { 1,2,3,4,5,6,7,8,9,10 };

	print_first_element(v);
}

// ���ø� ����� �����̳ʴ� �ڽ��� �����ϴ� Ÿ���� �ֽ��ϴ�.
// �� Ÿ���� �˰� �������� �ֽ��ϴ�. - ���� �ִ� print_first_element

// �׷��� list �� ���鶧 �Ʒ�ó�� ��������ϴ�.
template<typename T> class list
{
public:
//	typedef T value_type; // C++11���� ��Ÿ��
	using value_type = T; // C++11 ���� �ڵ� ��Ÿ��
};
list<int> s = { 1,2,3 };
list<int>::value_type n = s.front(); // n�� Ÿ���� ������ ������



