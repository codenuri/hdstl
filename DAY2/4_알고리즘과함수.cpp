#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"

// 알고리즘은 인자로 "함수"를 받는 경우가 많다.
// 단항 함수 : 인자가 1개인 것
// 이항 함수 : 인자가 2개인 것

// 값을 변경하려면 "int& e" 로 받으면 됩니다.
void foo(int e) {   std::cout << e << ", ";}

int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    
    // for_each 알고리즘
//    std::for_each(v.begin(), v.end(), foo);

    // C++11 부터는 "함수 보다 람다 표현식"을 사용하는 것이 편리합니다
    // [] : lambda introducer
    //      람다표현식이 시작됨을 알리는 기호.
    // 람다표현식 : 함수(이름)이 필요한 곳에, 함수 구현을 넣는 표현식
    std::for_each(v.begin(), v.end(), 
                        [](int e) { std::cout << e << ", "; } );

	return 0;
}



















//
