#include <iostream>
#include <ratio>

// chrono : 시간 관련 라이브러리.. 

// chrono 를 이해 하려면
// 1. ratio 을 공부하세요
// 2. duration 을 공부하세요
// 3. chrono 라이브러리 사용법을 익히세요.

int main()
{
	// std::ratio : 분수를 나타내는 "템플릿"
	//				서로 다른 분수는 "다른 타입" 입니다.
	// 아래 코드에서 r1, r2는 다른 타입입니다.
	std::ratio<1, 10> r1; // 1/10
	std::ratio<2, 10> r2; // 2/10 => 1/5

	// 만일 아래 처럼 만들었다면 r3, r4는 같은 타입입니다.
//	ratio r3(1, 10);
//	ratio r4(2, 10);
}

namespace std {

	//class template ratio
	template <intmax_t N, intmax_t D = 1>
	class ratio {
	public:
		typedef ratio<num, den> type;
		static constexpr intmax_t num;
		static constexpr intmax_t den;
	};


	// ratio arithmetic            
	template <class R1, class   R2> using   ratio_add = /*ratio*/;
	template <class R1, class   R2> using   ratio_subtract = /*ratio*/;
	template <class R1, class   R2> using   ratio_multiply = /*ratio*/;
	template <class R1, class   R2> using   ratio_divide = /*ratio*/;

	// ratio comparison            
	template <class R1, class R2> struct ratio_equal;
	template <class R1, class R2> struct ratio_not_equal;
	template <class R1, class R2> struct ratio_less;
	template <class R1, class R2> struct ratio_less_equal;
	template <class R1, class R2> struct ratio_greater;
	template <class R1, class R2> struct ratio_greater_equal;

	// convenience SI typedefs         
	typedef ratio<1, 1000000000000000000000000> yocto;
	typedef ratio<1, 1000000000000000000000> zepto;
	typedef ratio<1, 1000000000000000000> atto;
	typedef ratio<1, 1000000000000000> femto;
	typedef ratio<1, 1000000000000> pico;
	typedef ratio<1, 1000000000> nano;
	typedef ratio<1, 1000000> micro;
	typedef ratio<1, 1000> milli;
	typedef ratio<1, 100> centi;
	typedef ratio<1, 10> deci;
	typedef ratio<10, 1> deca;
	typedef ratio<100, 1> hecto;
	typedef ratio<1000, 1> kilo;
	typedef ratio<1000000, 1> mega;
	typedef ratio<1000000000, 1> giga;
	typedef ratio<1000000000000, 1> tera;
	typedef ratio<1000000000000000, 1> peta;
	typedef ratio<1000000000000000000, 1> exa;
	typedef ratio<1000000000000000000000, 1> zetta;
	typedef ratio<1000000000000000000000000, 1> yotta;

}
