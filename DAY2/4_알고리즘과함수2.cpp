#include <iostream>
#include <list>
#include <algorithm>
#include "show.h"

int foo(int a, int b) { return a + b; }

int main()
{
    std::list<int> s1 = { 1,2,3,4,5};
    std::list<int> s2 = { 6,7,8,9,10 };
    std::list<int> s3;

    // transform 알고리즘
//    std::transform(s1.begin(), s1.end(),   // 1. 이구간의 요소들을
//                   s2.begin(),             // 2. 이구간의 요소와 함께
//                   //s3.begin(),// 4. 함수의 결과를 여기에 담아달라
//                   std::back_inserter(s3), 
//                   foo);      // 3. 이 함수로 보내서

    // s1 과 s2 구간의 각 요소의 "곱"을 s3에 넣어 보세요
    // 단, 람다 표현식으로 해보세요.. 
    std::transform(s1.begin(), s1.end(), 
                   s2.begin(), 
                   std::back_inserter(s3),
                   [](int a, int b) { return a * b; });

    show(s3);

    std::list<int> s4;

    // transform 은 인자 4개인 버전도 있습니다.
    std::transform(s1.begin(), 
                   s1.end(),
                   std::back_inserter(s4),
                   [](int a) { return a * 10; });

    show(s4);
	return 0;
}



















//
