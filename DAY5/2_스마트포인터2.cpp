#include <iostream>

// 1. ����Ʈ�����ʹ� ��κ� ���ø����� ����� �˴ϴ�.

template<typename T> 
class Ptr
{
	T* obj;
public:
	Ptr(T* p = 0) : obj(p) {}
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
	~Ptr() {	delete obj;	}
};
int main()
{
	Ptr<int> p = new int;
	*p = 10;
	std::cout << *p << std::endl;

	// new �� ��������� delete �� ���� �ʾƵ� �˴ϴ�.
	// p�� �ı��ɶ� �ڵ����� delete �˴ϴ�.
}


