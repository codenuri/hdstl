#include <iostream>
#include <vector>
#include <list>

template<typename Container>
void show( const Container& c  )
{
	// �����̳��� ��� ����� range-for �� ���մϴ�.
	// range-for �� �迭�� ���� �մϴ�.
//	for (auto  e : c)	// c�� �� ��Ҹ� "e�� ����" �ؼ� ����ϰڴٴ°�
//	for (auto& e : c)	// c�� �� ��Ҹ� ������ ����Ű�ڴٴ°�
	for (const auto& e : c)
		std::cout << e << ", ";

	std::cout << std::endl;
}

// �ݺ��� ������ show
template<typename Iter>
void show(Iter first, Iter last)
{
	// typename Iter::value_type : Iter Ÿ���� �����Ͷ�� ����
	// typename std::iterator_traits<Iter>::value_type : �����͵� ����
	std::ostream_iterator< typename std::iterator_traits<Iter>::value_type > p(std::cout, ", ");

	std::copy(first, last, p);

	std::cout << std::endl;
}

int main()
{
	std::list<int> s = { 1,2,3,4,5 };
	int x[5] = {1,2,3,4,5};

	// show �� ����� ���ô�.
	show(s);
	show(x);


	show(s.begin(), s.end());
	show(x, x+5);
}