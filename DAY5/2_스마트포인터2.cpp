#include <iostream>

// 1. 스마트포인터는 대부분 템플릿으로 만들게 됩니다.

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

	// new 를 사용했지만 delete 를 하지 않아도 됩니다.
	// p가 파괴될때 자동으로 delete 됩니다.
}


