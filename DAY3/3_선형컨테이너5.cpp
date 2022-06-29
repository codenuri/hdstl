#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include "show.h"

// 컨테이너를 보관하는 컨테이너

int main()
{

	std::vector<int> v1(10, 0);
	
	v1[0] = 10;


	// vector가 vector를 보관하면 matrix 형태로 사용할수 있습니다.
//	std::vector<std::vector<int>> v2(10);
	std::vector<std::vector<int>> v2(10, std::vector<int>(10));
	
	v2[0][0] = 10; 

	// 아래 코드의 메모리 구조를 잘생각해 보세요
	// => 아래 구조를 C언어로 만든다고 생각해 보세요.. 아주 복잡한 코드가 됩니다.
	std::vector< std::list<int> > v3(10);
	
	v3[0].push_back(1);
	v3[0].push_back(2);
	v3[0].push_back(3);

	v3[1].push_back(10);
	v3[1].push_back(20);

	v3[2].push_back(300);
}







