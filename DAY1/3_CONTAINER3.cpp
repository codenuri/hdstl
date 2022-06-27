#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};

template<typename T> class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p)
	{
	}
	slist_iterator<T>& operator++()
	{
		current = current->next;
		return *this;
	}
	T& operator*() { return current->data; }

	bool operator==(const slist_iterator& it) { return current == it.current; }
	bool operator!=(const slist_iterator& it) { return current != it.current; }
};


template<typename T> class slist
{
	Node<T>* head = nullptr;
public:
	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}

	// 모든 컨테이너 설계자는 자신의 반복자 클래스 이름을
	// 약속된 형태로 외부에 알려야 합니다.
	using iterator = slist_iterator<T>; 
				// typedef slist_iterator<T> iterator


	iterator begin() { return iterator(head); }
	iterator end()   { return iterator(nullptr); }
};



int main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);

	slist<int>::iterator p = s.begin();
		// std::vector<int>::iterator p = v.begin()  <= vector 반복자

	std::cout << *p << std::endl; 
	++p;
	std::cout << *p << std::endl; 
}