// 5_함수객체5-1
#include <iostream>
#include <vector>
#include <algorithm>

/*
bool foo(int n)
{
	return n % k == 0; // error. 여기서 k 는 사용할수 없습니다.
}
*/

class IsDivide
{
	int value;
public:
	IsDivide(int n) : value(n) {}

	bool operator()(int n) // 이 함수 때문에 인자가 한개인 함수 처럼 사용가능
	{
		return n % value == 0;
	}
};

int main()
{
	int k = 4;
	std::vector<int> v = { 1,9,3,4,5,6,7,8,9,10 };
	
	IsDivide f(k);	// 함수 처럼 사용가능한 객체를 만들때
					// main 의 지역변수인 "k" 를 전달
	bool b = f(10); // 10 % k == 0 조사. 즉 4의 배수인가 조사
					// f.operator()(10)
	auto ret2 = std::find_if(v.begin(), v.end(), f );

	// 함수 객체 사용시. 한번만 사용한다면 "임시객체"형태로 전달해도 됩니다.
	// "클래스이름()" : 객체를 생성하는 표기법 입니다.
	auto ret3 = std::find_if(v.begin(), v.end(), IsDivide(k) );
}
// 핵심
// 일반 함수는 상태를 가질수 없지만
// 함수 객체는 상태를 가질수 있습니다.(멤버 데이타가 있다는 의미)
// 그래서, 위의 IsDivide 처럼. main 에서 사용하던, 지역변수를 함수 객체에 전달해서
// 사용 가능합니다
// => "클로져"라고 합니다.