#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

// ������ ����� ���� �Լ�
void foo(int* arr, int sz) {}

int main()
{
	// C��� : �迭 ���. 
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	foo(x, 10);

	// �迭    : ũ�� ������ �Ҽ� ����.
	// vector : ũ�� ���� ����

	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// vector �� ����ϴµ�, ������ ����� ���� foo�� vector�� ������ �ʹ�.
	// foo �� v�� ���� ������.
//	foo( v, v.size() ); // error
//	foo(&v, v.size()); // error

	foo(&v[0],    v.size()); // ok.. ������ ����ϴ� �ڵ� ( C++11 ����)
	foo(v.data(), v.size()); // ok.. ���� ��Ÿ��( C++11 ����)

	// ����
	// �ݺ��ڰ� ����Ű�� ��ü�� �ּҸ� �˰� ���� ��, �ݺ��� ��� ������ �������?
	// v.begin() �� ����� ���� �ֳ���?

	auto p = v.begin();
	++p;

	foo(&(*p), v.size() - 1);  // ok..�ݺ��ڰ� ����Ű�� ����� �ּ� ������

	foo(&(*v.begin()), v.size()); // ok

	// &p : �ݺ��� ��ü�� �ּ�
	// *p : �ݺ��ڰ� ����Ű�� ���� ��ü ����
	// &(*p) : �ݺ��ڰ� ����Ű�� ���� ��ü�� �ּ�
}


