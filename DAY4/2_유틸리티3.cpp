#include <iostream> // 표준 입출력 스트림
#include <fstream>  // 화일 스트림
#include <sstream>  // 메모리(스트링)스트림
#include <string>

// C++ 표준에 아래 처럼 되어 있습니다.
/*
namespace std
{
	// 1. C++ 표준 입출력 스트림 - <iostream>
	class ostream {};
	ostream cout;

	// 2. C++ 파일 입출력 스트림 - <fstream>
	class ofstream {}; 
	class ifstream {};

	// 3. C++ 메모리 입출력 스트름 - <sstream>
	class ostringstream {};
	class istringstream {};
}
*/
int main()
{
	// 1. 표준 출력 객체는 이미 "cout" 이 생성되어 있으므로 사용하면 됩니다.
	std::cout << "hello";

	// 2. 파일 입출력이 필요하면 "파일 스트림"객체를 만들어 사용하면 됩니다
	std::ofstream fout("a.txt");

	fout << "hello"; // cout 과 사용법이 동일합니다.

	// 3. 메모리(문자열)출력
	std::ostringstream oss;
	oss << "hello";

}
