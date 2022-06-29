#include <list>
#include <vector>

// STL ��� �����̳��� ������ Ư¡

int main()
{
	std::list<int> s = { 1,2,3 };

	// 1. ��� Ÿ���� �ִ�.
	std::list<int>::value_type n = s.front(); // int n

	// ? �� �� �ּ��� Ÿ���� ?
	unsigned int sz = s.size();
	std::list<int>::size_type sz2 = s.size(); // �̹���� �ּ��Դϴ�.

	auto sz2 = s.size(); // C++11 ���ʹ� �̷��� 



	// 2. ����Լ��� ��ȯ�� ���Ÿ� ���ÿ� ���� �ʴ´�.
	// => �׷���, �����ϰ� �����ϴ� �е��� �����ϴ�
	// => �׷���, �̷��� �ؾ����� ���� ������ �ڵ带 ����� �ִٴ�
	//    �̷��� �ֽ��ϴ�.
	int n = s.back();	// ��ȯ��. ���ŵ��� �ʴ´�.
	s.pop_back();		// ���Ÿ� �Ѵ�. ��ȯ Ÿ���� void




	// 3. ���� ������ ���� ����Ѵ�.
	std::list<int, MyAlloc<int>> s2;	// �޸� �Ҵ� ��� ����

	std::set<int, std::greater<int>,   // �� ��å ����
				  MyAlloc<int>> ss;	   // �޸� �Ҵ� ��� ����
}



