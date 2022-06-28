#include <iostream>
#include <iterator>
#include <list>

int main()
{
	int n = 10;

	std::cout << n << std::endl;


	// stream iterator
	std::ostream_iterator<int> p(std::cout, " ");

	*p = 10; // std::cout << 10 << " " �� �ǹ�.
	++p;     // �� �ݺ��ڴ� ++ �����ڰ� �ϴ����� ������, 
			 // ����ص� ������ �ƴմϴ�.
			 // => std::copy �� �� �ݺ��ڸ� �����Ϸ��� ++�� �Ǿ�� �մϴ�
	*p = 20; 


	std::list<int> s = { 1,2,3 };
	std::copy(s.begin(), s.end(), p);

}