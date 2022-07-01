#include <iostream>

// 2. 스마트포인터는 얕은 복사 문제를 해결해야 합니다.
// 깊은 복사 : 스마트 포인터 만들때는 사용 안함.
// 참조 계수 : 스마트 포인터 만들때 가장 널리 사용
// 복사 금지 : 스마트 포인터 만들때 역시 널리 사용

template<typename T>
class Ptr
{
	T*   obj;
	int* ref;  // 참조계수용 변수를 가리키는 포인터
public:
	Ptr(T* p = 0) : obj(p) 
	{
		ref = new int;
		*ref = 1;
	}



	T* operator->() { return obj; }
	T& operator*() { return *obj; }
	~Ptr() { delete obj; }
};



int main()
{
	Ptr<int> p1 = new int;
	Ptr<int> p2 = p1; 
}


