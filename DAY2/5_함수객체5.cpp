#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n)
{
	return n % 3 == 0;
}

int main()
{
	std::vector<int> v = { 1,9,3,4,5,6,7,8,9,10 };

	// 주어진 구간에서 "3의 배수"를 찾아라!
	auto ret1 = std::find_if(v.begin(), v.end(), foo);

	// 핵심 : 아래 코드 생각 해 보세요
	int k = 0;
	std::cin >> k;

	// 주어진 구간에서 "k의 배수"를 찾아라!!
	// => ? 를 채워 보세요.. 
	auto ret2 = std::find_if(v.begin(), v.end(), ?);

	// ret1, ret2 는 결국 반복자 입니다. *ret1 하면 요소 출력됩니다.
	std::cout << *ret1 << std::endl;
}

// 핵심 1. 일급 객체(first-class object)
// => 함수의 인자나 반환 값으로 사용가능한 객체
// => int n, double d 에서 n, d 모두 1급 객체 입니다

// 핵심 2. 함수는 일급 객체인가 ?
// => C/C++에서 함수를 인자로 보내 거나 받을수 있으므로 1급 객체이다.

// 핵심 3. "Closure" 라는 용어 => 거의 모든 언어에서 사용되는 용어
// => 문맥(위코드는 main 함수)에 속한 지역변수를 캡쳐해서 인자로 전달 가능한
//    일급 객체..
// => C/C++의 함수는 "일급객체" 지만 "Closure"가 될수는 없다.

// find_if  의 세번째 인자값으로 받는 함수로는 무조건 하나의 인자밖에 
// 전달해주지 못하는건 find_if 함수의 약속인건가요? => 네 맞습니다. 
//									무조건 단항 함수로 약속되었습니다.
