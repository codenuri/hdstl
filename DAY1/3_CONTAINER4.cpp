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

	using iterator = slist_iterator<T>;


	iterator begin() { return iterator(head); }
	iterator end() { return iterator(nullptr); }
};

template<typename T1, typename T2>
T1 find(T1 first, T1 last, T2 c)
{
	while (first != last && *first != c)
		++first;

	return first;
}

int main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);

	// ���� find �� �迭�� �ƴ϶� list ������(�ᱹ ��� �ڷᱸ��)
	// "���� �˻�" �� �����Ҽ� �ֽ��ϴ�.
	// => STL �� ���� ö��!
	slist<int>::iterator p = find(s.begin(), s.end(), 30);

	if (p == s.end())
	{
		std::cout << "�˻� ����" << std::endl;
	}
	else
	{
		std::cout << "�˻� ���� : " << *p << std::endl;
	}
}