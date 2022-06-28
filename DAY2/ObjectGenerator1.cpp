// ObjectGenerator1.cpp
template<typename T>
T square(T a)
{
	return a * a;
}

template<typename T> class list
{
public:
	list(int sz, T value) {}
};

// C++14까지는 클래스 템플릿은 항상 타입인자를 전달해야 합니다.
// 이 경우 좀 복잡해 보일수 있습니다.
// 함수 템플릿의 도움을 얻으면 편리합니다.
template<typename T> 
list<T> make_list(int sz, T value)
{
	return list<T>(sz, value);
}

int main()
{
	// 다음중 쉬워 보이는 것은 ?
	square<int>(3);	// 함수 템플릿을 사용하는 정확한 표기법
	square(3);		// 타입 인자 생략시, 컴파일러가 함수 인자를 보고
					// T의 타입 추론

	// 클래스 템플릿과 타입 추론
	list<int> s1(10, 3);
	list      s2(10, 3); // 생성자 인자를 통한 타입 추론 ?
						 // C++17 부터 가능한 문법
						 // C++14 까지는 안됩니다.

	auto s3 = make_list<int>(10, 3); // 타입을 전달한 정확한 표기법

}
// type deduction은 parameter가 있는 경우만 가능하겠네요? => 네 안됩니다