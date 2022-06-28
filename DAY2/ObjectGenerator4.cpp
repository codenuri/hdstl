template<typename T>
class list
{
public:
	list() {}
	list(int sz) {}
	list(int sz, T value) {}
};

// class template type deduction guide 라는 문법입니다. => C++17
// 생성자모양 -> list<타입>
list(int sz)->list<int>;

int main()
{
	list s1(10, 3); // ok.. 생성자 인자로 T 타입 추론 가능, C++17부터
	list s2(10);    // 
}