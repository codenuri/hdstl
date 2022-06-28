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
    std::transform(s1.begin(), s1.end(),   // 1. 이구간의 요소들을
                   s2.begin(),             // 2. 이구간의 요소와 함께
                   //s3.begin(),// 4. 함수의 결과를 여기에 담아달라
                   std::back_inserter(s3), 
                   foo);      // 3. 이 함수로 보내서

    show(s3);

	return 0;
}



















//
