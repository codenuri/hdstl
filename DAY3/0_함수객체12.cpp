// 오늘 받으신 DAY3.zip 압축 풀고 열어 주세요.
// 함수객체5 ~ 함수객체10 까지는 "프로젝트에서 제거" 해주세요.

// 함수객체 12.cpp
#include <iostream>
#include <functional> // C++ 표준 함수객체
#include <algorithm>  
#include <vector>
#include "show.h"

bool cmp1(int a, int b) { return a < b; }
int main()
{
	std::vector<int> v = { 1,3,5,7, -9 ,2,4,6,8,10 }; // 9 만 음수

	// sort 방법
	// 1. 오름 차순으로 하고 싶다. - 비교 정책 전달하지 않아도 됩니다.
	std::sort(v.begin(), v.end());
	show(v);

	// 2. 내림 차순으로 하고 싶다. - std::greater<int> 전달하세요
	std::sort(v.begin(), v.end(), std::greater<int>() );
	show(v);

	// 3. 절대값 오름 차순으로 하고 싶다. 
	// => 표준에 절대값으로 비교하는  함수 객체는 없습니다. 
	// => 사용자가 만들어야 합니다.
	// => 1. 클래스를 직접 만들기
	// => 2. 람다 표현식으로 컴파일러에게 요청하기.
	std::sort(v.begin(), v.end(), 
					[](int a, int b) { return abs(a) < abs(b); });
	show(v);

	// 4. 데이타 양이 적거나, 
	//    속도 보다는 메모리 사용량이 중요한 환경이라면
	//    "람다표현식이나 함수객체" 보다는 "일반함수(포인터)"를 비교 정책으로 사용
	std::sort(v.begin(), v.end(), cmp1); 
	show(cmp1);
}

