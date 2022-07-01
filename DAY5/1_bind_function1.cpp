#include <iostream>
#include <algorithm>
#include <functional>
using namespace std::placeholders; // _1, _2, _3 .... 
// 161 page
// 
// 4항 함수
void foo( int a, int b, int c, int d)
{
    printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
    foo(1,2,3,4);   // 4항 함수..

    // std::bind : M항 함수(객체)의 특정인자를 고정한 새로운 함수를 만드는 도구
    // std::bind(M항함수, M개인자)

    std::bind(&foo, 5, 8, _1, _2)(4, 2); // 4항함수 => 2항 함수로 변경한것
    //|<------_ 함수 반환 ------->|       // 결국 foo(5, 8, 4, 2) 

    std::bind(&foo, 5, 8, 1, 3)(); // 4항 함수 => 0항 함수로 변경한것


    std::bind(&foo, ? , ? , ? , ? )(6, 3, 2); // 3, 1, 2, 6 나오게해보세요
}


