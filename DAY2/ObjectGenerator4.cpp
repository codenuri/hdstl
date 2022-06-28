#include <vector>

template<typename T>
class list
{
public:
	list() {}
	list(int sz) {}
	list(int sz, T value) {}

	template<typename C> 
	list(C& c) {}

	template<typename IT>
	list(IT first, IT last) {}
};
// class template type deduction guide ��� �����Դϴ�. => C++17
// �����ڸ�� -> list<Ÿ��>
list(int sz)->list<int>;

template<typename C>
list(C& c)->list< typename C::value_type >;

template<typename IT>
list(IT first, IT last)->list<typename std::iterator_traits<IT>::value_type>;

int main()
{
	list s1(10, 3); // ok.. ������ ���ڷ� T Ÿ�� �߷� ����, C++17����
	list s2(10);    // 

	std::vector v = { 1,2,3 };

	list s3(v); // v�� ������ ��ҷ� �ʱ�ȭ �ش޶�.
			    // ���ڵ尡 �ǵ��� ����� ���ô�.
	list s4(v.begin(), v.end());
}