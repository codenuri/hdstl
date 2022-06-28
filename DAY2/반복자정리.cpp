// 반복자정리

// 정의 : 포인터와 유사하게 동작하는 객체
//      => ++로 이동가능하고, *로 요소에 접근할수 있다면 반복자이다.

// 반복자의 형태
// 1. 컨테이너에서 꺼내기  => s.begin() / s.rbegin() / s.cbegin() / s.crbegin();
// 
// 2. raw pointer 도 반복자
// 
// 3. 독립된 객체로 만들어 사용하는 반복자들
//  => 삽입반복자 3개, 스트림 반복자, reverse_iterator, directory_iterator

// 반복자 카테고리 5개 ( 입력, 출력, 전진, 양방향, 임의접근)
//  => 각 컨테이너가 가진 반복자의 카테고리는 무엇인가 ?
//  => 각 알고리즘은 어떤 반복자를 요구 하는가 ?


// 반복자가 가리키는 요소의 타입을 얻는 방법
// => typename T::value_type                        : T 가 raw pointer 라면 error
// => typename std::iterator_tratis<T>::value_type  : raw pointer도 가능

// 반복자의 무효화 현상
std::vector<int> v(5);
auto p = v.begin();
v.resize(10); // 이순간 vector의 내부 버퍼 변경
              // 기존에 꺼냈던 반복자는 모두 무효화 됩니다.

// 각 컨테이너별 반복자 카테고리
// std::list<int>   : 양방향
// std::vector<int> : 임의 접근