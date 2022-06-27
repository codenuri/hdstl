#include <iostream>

// 30 page ~ 
// 싱글리스트를 생각해 봅시다.

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};


// slist 안에 있는 Node 를 가리키는
// 포인터 역활을 하는 클래스 설계
template<typename T> class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p)
	{
	}
	// find 에 보내려면 ==, !=, ++, * 연산이 가능해야 합니다.
	slist_iterator<T>& operator++()
	{
		current = current->next;
		return *this;
	}
	T& operator*() { return current->data; }

	bool operator==(const slist_iterator& it) { return current == it.current ; }
	bool operator!=(const slist_iterator& it) { return current != it.current; }
};
// 아래 p 는 진짜 포인터는 아니지만, 연산자 재정의 기술로
// 포인터 처럼 동작하게 만들었습니다.
// list 는 각 요소는 "연속된 메모리가 아니지만" 
// 마치 연속된 메모리 인것 처럼 ++p 로 해서 각 요소를 이동할수 있습니다.
// "반복자(iterator)" 라고 부릅니다.
// 
//slist_iterator p(500번지);
//++p; // p가 진짜포인터면 무조건 다음주소로 이동
	 // p가 객체라면 "p.operator++()" 호출
//*p;













template<typename T> class slist
{
	Node<T>* head = nullptr;
public:
	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}

	// 모든 컨테이너 설계자는 자신의 처음과 마지막 다음을 가리키는 
	// 반복자를 반환하는 함수를 제공하기로 약속 합니다.
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

	// list 는 모든 요소가 떨어진 자료구조지만
	// iterator 를 사용하면 ++로 모든 요소를 이동할수 있습니다.
	// iterator 는 "연산자 재정의 기술"로 만들어진 포인터 역활의 객체 라고생각하세요

	slist_iterator<int> p = s.begin();

	// 이제 p 를 포인터라고 생각하고 사용하시면 됩니다.
	std::cout << *p << std::endl; // 50
	++p;
	std::cout << *p << std::endl; // 40
}