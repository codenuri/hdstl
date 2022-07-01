#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

// 이항 함수 입니다.
bool foo(int a, int b)
{
    return a % b == 0;
}

int main()
{
    std::vector<int> v = {1,9,2,3,4,5,6,7}

    int k = 3;

    // 주어진 구간에서 k의 배수를 찾고 싶다.
//  auto ret = std::find_if(v.begin(), v.end(), foo ); // error
                    // => find_if 는 단항 함수를 요구하는데 foo 는 이항 함수 입니다.

    auto ret = std::find_if(v.begin(), v.end(), std::bind(&foo, _1, k) ); 
                    // => ok. foo 의 2번째 인자를 k값으로 고정

    // 그런데, 위처럼 할수도 있지만
    // 이 경우에는 "람다 표현식"이 더 좋습니다.
    auto ret2 = std::find_if(v.begin(), v.end(), 
                            [k](int n) { return n % k == 0; });
                     // [k] : 람다표현식안에서 지역변수 k를 사용하겠다는 문법
}

















//












//
