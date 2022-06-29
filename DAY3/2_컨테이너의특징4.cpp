#include <set> // Red Black Tree
#include <functional>
#include <iostream>
// 107 ~ 108

// ���� ���� ������ ( policy base design )
// => Ŭ������ ����ϴ� �پ��� ��å�� template ���ڷ� ��ü�ϴ� ���

// 1. �����̳��� �޸� �Ҵ� ����� ���ø� ���ڸ� ���ؼ� "����� ���� allocator" 
//    �� ����

// 2. set ���� �����̳��� ��� �񱳵� ���ø� ���ڷ� ��ü


// STL set �� ������ �Ʒ��� �����ϴ�.
/*
template<typename T,					// ������ Ÿ��
	     typename PR = std::less<T>,	// ��Ҹ� ���Ҷ� ������Լ���ü
		 typename Alloc = std::allocator<T> >
class set
{ 
	// tree �� �ʿ��� �����
	Alloc ax; // �޸� �Ҵ��
	PR    f;  // �񱳿� ����� �Լ� ��ü
public:
	void insert(const T& elem)
	{
		// ���� 2�� ����� ũ��񱳸� �Ʒ� ó�� ���� "<" �� ��� �ߴٸ�
		// ����ڰ� ����� �� ��å�� ��ü �Ҽ� ���� �˴ϴ�.
		if (root->elem < elem)
		{
		}
		// �׷��� �Ʒ� ó�� 2��° ���ø� ���ڷ� ���޵� Ÿ���� ��ü(�Լ���ü)
		// �� ����ؼ� �� �ϰ� �ֽ��ϴ�.
		if (f(root->elem, elem)) // ũ�� �񱳽� ���ø� 2��° ���ڷ� ����
		{						   // ��ü ���
		}
	}	
};
*/
int main()
{
//	std::set<int> s; // Red Black Tree �Դϴ�. std::less<int> �� ��� ��

	std::set<int, std::greater<int> > s;
					// ū���� ���ʿ�, ���� ���� ������

	s.insert(15);
	s.insert(25);
	s.insert(5);
	s.insert(17);
	s.insert(10);

	auto p = s.begin();

	while (p != s.end())
	{
		std::cout << *p << ", ";
		++p;
	}
	std::cout << std::endl;
}