class Test
{
public:
	enum { value = 1 };
	typedef int DWORD;
};
int p = 0;

template<typename T> void foo(T a)
{
	// 아래 2줄에서 * 의 의미를 생각해 보세요(1. 곱하기, 2. 포인터 변수 선언)
	
	// 클래스이름::"이름" 에서 "이름"의 의미
	// 1. 값   일수 있다. : enum 상수, static 멤버 데이타등.
	// 2. 타입 일수 있다. : typedef 또는 using 등.. 
	
//	Test::value * p; // 곱하기의 의미
//	Test::DWORD * p; // 포인터 변수 p를 선언하는 코드

	// dependent name : 템플릿 인자 T 에 의존한 이름
	//					컴파일러는 기본 적으로 "값"으로 해석
	T::value * p; // ok
//	T::DWORD * p; // error
	typename T::DWORD* p;	// ok.. depedent name 이 
							// 타입의 이름이라고 알려주는 것
}


int main()
{
	Test t;
	foo(t);
}