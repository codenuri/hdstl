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

	// 참조 계수 기반으로 만든 복사 생성자
	Ptr(const Ptr& p)
		: obj(p.obj), ref(p.ref) // 모든 멤버를 얕은복사후에
	{
		++(*ref); // 참조 계수 1증가
	}
	
	// 참조계수를 사용할때의 소멸자 모양
	~Ptr() 
	{ 
		if (--(*ref) == 0)
		{
			delete obj; // 자원 제거
			delete ref; // 참조계수도 제거
		}
	}

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
	
};



int main()
{
	Ptr<int> p1 = new int;
	Ptr<int> p2 = p1; 
}


