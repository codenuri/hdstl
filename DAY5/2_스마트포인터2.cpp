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

	// 그런데, 아래 처럼 사용하면 실행시간에 오류가 발생합니다
	Ptr<int> p2 = p; // 이순간 복사 생성자가 호출되는데,,
					// 컴파일러가 제공한 복사 생성자는 
					// "얕은 복사" 현상 발생
}


