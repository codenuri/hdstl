// 3_함수객체8
// 
// 1. 일반 함수는 자신만의 타입이 없습니다.
//    signature(리턴타입과 파라미터) 가 
//    동일한 모든 함수는 같은 타입입니다.

// 2. 함수 객체는 자신만의 타입이 있다.
//    signature 가 동일 해도 모든 함수객체는 다른 타입이다.


struct Less
{
	inline bool operator()(int a, int b) { return a < b; }
};
struct Greater
{
	inline bool operator()(int a, int b) { return a > b; }
};

//===================================================
// 정책 교체가 가능한데, 정책함수의 인라인 치환을 지원하는 함수 만들기
// "템플릿" + "함수객체" 의 조합으로 만드는 기술
// => STL 의 핵심 설계 철학... 

// 이해 되신분은 "단점"은 뭘까요 ?
template<typename T>
void Sort(int* x, int sz, T cmp)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (cmp(x[i], x[j]) == true)	
				std::swap(x[i], x[j]);
		}
	}
}

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; f1(1, 2); Sort(x, 10, f1);
	Greater f2; f2(1, 2); Sort(x, 10, f2);
}



