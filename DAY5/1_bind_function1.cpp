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


    std::bind(&foo, _2, 1, _3, _1 )(6, 3, 2); // 3, 1, 2, 6 나오게해보세요
    // => 4항 함수 이던 foo 의 2번째 인자를 고정해서
    // => 3항 함수로 만들어서 사용하는 것
}
// foo 이름 자체가  주소인데, &foo로 보내야 하나요?
// foo : 함수 주소가 아닌, 함수이름(함수 타입)입니다.
//       그런데, 함수 이름은 함수 주소로 암시적 형변환 되므로 이름만 사용가능합니다.
//       std::bind(foo, ...) 처럼 해도 됩니다.

// 그런데, 주의 사항. 멤버함수는 이름이 주소로 변환되지 않습니다.
// 반드시 & 적어야 합니다.
// std::bind(Dialog::foo,  ...); // error
// std::bind(&Dialog::foo,  ...); // ok

