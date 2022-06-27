#include <iostream>

// 30 page ~ 
// �̱۸���Ʈ�� ������ ���ô�.

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};

template<typename T> class slist
{
	Node<T>* head = nullptr;
public:
	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}
};
int main()
{
	// �Ʒ� �ڵ� ����� �޸� �׸���
	// 31 page�� �ֽ��ϴ�
	slist<int> s;
	
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);
}