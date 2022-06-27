#include <iostream>

// 30 page ~ 
// 싱글리스트를 생각해 봅시다.

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
	// 아래 코드 실행시 메모리 그림이
	// 31 page에 있습니다
	slist<int> s;
	
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);
}