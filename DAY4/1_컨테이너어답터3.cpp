#include <list>
#include <vector>
#include <deque>
#include <stack>
#include <queue> // queue, priority_queue
#include "show.h"

int main()
{
	// ������ ������ ��� ��� ������
	// stack : ���ʸ� ���� ������ �˴ϴ�. list, vector, deque ��� ����
	std::stack<int, std::list<int>>   s1;
	std::stack<int, std::vector<int>> s2;
	std::stack<int, std::deque<int>>  s3;

	// queue : ������ ���� �־�� �մϴ�. vector �� �ȵ˴ϴ�.
	std::queue<int, std::list<int>>   q1;
	std::queue<int, std::vector<int>> q2; // �̷��� ������� ������
	std::queue<int, std::deque<int>>  q3;

	q2.push(10); // ok.. ������ �����ϴ�.
				 // ������ ���ٴ� ���� �������� vector�� push_back ��
				 // ����ߴٴ°�
	q2.pop();	// vector �� pop_front() �� �������µ�..
				// vector �� ������ �������Ƿ� ����..
}



