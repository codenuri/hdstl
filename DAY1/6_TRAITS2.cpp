#include <iostream>
#include <list>
#include <vector>

// C++���� �ݺ��� ���� : �ݺ��� ó�� �����ϴ� ��� ���� �ݺ��� �̴�.
//					  => ++�� �̵������ϰ�, *�� ��� ������ ������ ����!

// �ݺ����� 2���� ����
// 1. raw pointer
// 2. Ŭ���� �������� ������� ����(�츮�� ���� slist_iterator ó��)

// �׷���, ��ü�� �ݺ��� �ȿ��� "value_type" �� ������
// raw pointer ���� "value_type"�� ����. 

// �� 2���� ������������ ����� ������ �ذ��ϴ� ����..
// => std::iterator_traits

template<typename T> struct iterator_traits
{
	using value_type = typename T::value_type;
};

// T = raw pointer �� ���� ������ �����ϱ� ���� �κ� Ư��ȭ
template<typename T> struct iterator_traits<T*>
{
	using value_type = T;
};


template<typename T>
//typename T::value_type sum(T first, T last)
typename iterator_traits<T>::value_type sum(T first, T last)
{
//	typename T::value_type s = 0;

	typename iterator_traits<T>::value_type s = 0;

	while (first != last)
	{
		s = s + *first;
		++first;
	}
	return s;
}
int main()
{
	// std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	// std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	int s[10] = {1,2,3,4,5,6,7,8,9,10};

	int n = sum(std::begin(s), std::end(s)); // �� �ڵ��
//	int n = sum(s,			   s+10);		 // �� �ڵ�� �ᱹ �����մϴ�.

	std::cout << n << std::endl; // 55
}