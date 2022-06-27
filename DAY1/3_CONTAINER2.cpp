#include <iostream>

// 30 page ~ 
// �̱۸���Ʈ�� ������ ���ô�.

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};


// slist �ȿ� �ִ� Node �� ����Ű��
// ������ ��Ȱ�� �ϴ� Ŭ���� ����
template<typename T> class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p)
	{
	}
	// find �� �������� ==, !=, ++, * ������ �����ؾ� �մϴ�.
	slist_iterator<T>& operator++()
	{
		current = current->next;
		return *this;
	}
	T& operator*() { return current->data; }

	bool operator==(const slist_iterator& it) { return current == it.current ; }
	bool operator!=(const slist_iterator& it) { return current != it.current; }
};
// �Ʒ� p �� ��¥ �����ʹ� �ƴ�����, ������ ������ �����
// ������ ó�� �����ϰ� ��������ϴ�.
// list �� �� ��Ҵ� "���ӵ� �޸𸮰� �ƴ�����" 
// ��ġ ���ӵ� �޸� �ΰ� ó�� ++p �� �ؼ� �� ��Ҹ� �̵��Ҽ� �ֽ��ϴ�.
// "�ݺ���(iterator)" ��� �θ��ϴ�.
// 
//slist_iterator p(500����);
//++p; // p�� ��¥�����͸� ������ �����ּҷ� �̵�
	 // p�� ��ü��� "p.operator++()" ȣ��
//*p;













template<typename T> class slist
{
	Node<T>* head = nullptr;
public:
	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}

	// ��� �����̳� �����ڴ� �ڽ��� ó���� ������ ������ ����Ű�� 
	// �ݺ��ڸ� ��ȯ�ϴ� �Լ��� �����ϱ�� ��� �մϴ�.
	slist_iterator<T> begin() { return slist_iterator<T>(head); }
	slist_iterator<T> end()   { return slist_iterator<T>(nullptr); }
};

int main()
{

	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);

	// list �� ��� ��Ұ� ������ �ڷᱸ������
	// iterator �� ����ϸ� ++�� ��� ��Ҹ� �̵��Ҽ� �ֽ��ϴ�.
	// iterator �� "������ ������ ���"�� ������� ������ ��Ȱ�� ��ü �������ϼ���

	slist_iterator<int> p = s.begin();

	// ���� p �� �����Ͷ�� �����ϰ� ����Ͻø� �˴ϴ�.
	std::cout << *p << std::endl; // 50
	++p;
	std::cout << *p << std::endl; // 40
}