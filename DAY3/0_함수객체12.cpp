// 오늘 받으신 DAY3.zip 압축 풀고 열어 주세요.
// 함수객체5 ~ 함수객체10 까지는 "프로젝트에서 제거" 해주세요.

// 함수객체 12.cpp
#include <iostream>
#include <functional> // C++ 표준 함수객체
#include <algorithm>  
#include <vector>
#include "show.h"

int main()
{
	std::vector<int> v = { 1,3,5,7, -9 ,2,4,6,8,10 }; // 9 만 음수

	// sort 방법
	// 1. 오름 차순으로 하고 싶다.
	std::sort(v.begin(), v.end());
	show(v);
}