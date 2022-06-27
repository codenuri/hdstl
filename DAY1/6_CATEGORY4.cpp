#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// std::advance() �� ������ ������ ���ô�.
/*
// 1. 5���� �ݺ��� ī�װ��� Ÿ��ȭ �մϴ�.
// => �ƹ� ����� ���� "empty class" ������
// => �ϳ��� ������ Ÿ���Դϴ�. 
// => �Լ� �����ε����� ���ڷ� ��밡���մϴ�.
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

// 2. �� �����̳��� �ݺ��ڸ� ���� �Ҷ�
//    �ڽ��� ��� ī�װ� ���� "��ӵ� ���"���� �ܺο� �˷��� �մϴ�.
template<typename T> class vector_iterator
{
public:
	// "iterator_category" ��� �̸����� �ܺο� �˸���� ��ӵ�.
	using iterator_category = random_access_iterator_tag;
};

template<typename T> class list_iterator
{
public:
	// "iterator_category" ��� �̸����� �ܺο� �˸���� ��ӵ�.
	using iterator_category = bidirectional_iterator_tag;
};
*/
// enum���� ���� ���ϴ� ������ �������? => �Ʒ� �ڵ� ������ ������
// 
// typename���� �˷��̴ּ� "value_type" �� 
// "iterator_category" ó�� ��ӵ� ǥ���ΰ��ΰ���? => ��Ȯ �մϴ�.!!

//----------------------
// ���� advance �� ī�װ� ���� ����
template<typename T>
void advance_imp(T& p, int sz, std::random_access_iterator_tag)
{
	p = p + sz;
	std::cout << "random ����" << std::endl;
}
template<typename T>
void advance_imp(T& p, int sz, std::input_iterator_tag)
{
	while (sz--)
		++p;	
	std::cout << "random �ƴ� ����" << std::endl;
}
template<typename T>
void advance(T& p, int sz) // sz > 0 �϶��� ����ϰڽ��ϴ�.
{
	// ���⼭�� �ݺ����� ������ ���� ���� �ִ� �Լ��� ȣ���մϴ�.
	// �ݺ��� T�� ������ T �ȿ� ��ӵ� ����(iterator_category) �� 
	// �����մϴ�
	// T::iterator_category : 5�� ������ Ÿ���� �Ѱ� �Դϴ�.

	// "Tag Dispatching" �̶�� �Ҹ��� "���� ������ ���" �Դϴ�.
	advance_imp(p, sz, typename T::iterator_category() );
}


int main()
{
	//	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = s.begin();

	advance(p, 5); 

	std::cout << *p << std::endl;
}