#include <iostream>
#include <list>
#include <algorithm>
#include <iterator> 


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,3,9,10 };

//	auto p1 = s.begin();
//	auto p2 = s.end();

	// �Ʒ� ó�� �ϱ����ؼ�, 
	// ���ڷ� ���޵� �ݺ��ڰ� ����Ű�� ��Һ��� ���� �Ѱ� ���� ����Ű���� ����Ǿ����ϴ�.
//	auto p1 = std::make_reverse_iterator(s.end());
//	auto p2 = std::make_reverse_iterator(s.begin());
	
	auto p1 = s.rbegin(); // std::make_reverse_iterator(s.end())�͵���
	auto p2 = s.rend();

	// �־��� ��������, ó�� ������ 3�� ã�� �ʹ�.
	// ��κ��� STL �˰����� �ݺ��ڸ� ++�� �̵��մϴ�.
	// ������, ���ݺ��� ���п�, ��κ��� �˰����� �������ε� �����Ҽ� �ֽ��ϴ�.
	auto ret = std::find(p1, p2, 3);
}
