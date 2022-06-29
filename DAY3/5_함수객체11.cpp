// 5_함수객체10
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // C++98 부터 지원되는 C++ 표준 함수 객체들

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// 비교정책으로 함수객체를 전달하는 코드
	std::sort(v.begin(), v.end(), std::less<int>());

	// 비교 정책으로 "람다표현식"을 사용하는 코드 - C++11
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; } );

	// 람다표현식을 사용하면 컴파일러가 아래 코드를 생성합니다
	// 위 한줄은 아래 나머지 부분과 완전히 동일합니다
	class CompilerGeneratedName
	{
	public:
		inline bool operator()(int a, int b) const
		{
			return a < b;
		}
	};
	std::sort(v.begin(), v.end(), CompilerGeneratedName() );
	//============================
	// 결론 : 람다 표현식은 "함수 객체"를 생성하는 표기법입니다.
	// => 람다 표현식을 보고 컴파일러가 위와 같은 클래스를 만들고
	// => 람다 표현식이 사용된 자리에 "임시객체" 형태로 전달하게 됩니다
}

// 일반 함수  (정확히는 해당 일반 함수의 포인터)로 전달되어도 컴파일 때 
// 특정 일반 함수로 지정이 된다면 치환 가능할것 같은데, 그렇게 안하는 이유가 있을까요?
// sort(x, x+10, cmp1); // 이때 만약 sort 안에 cmp1을 치환하면
// sort(x, x+10, cmp2); // 이때는 어떻게 할까요 ??
