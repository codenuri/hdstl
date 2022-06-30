#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <algorithm>

int main()
{
	std::ifstream fin("4_map2.cpp"); // 파일 하나 구해 두세요

	std::map<std::string, std::list<int>> indexMap; // 핵심 자료구조
	std::string s;
	int no = 0;

	while (std::getline(fin, s)) // 파일에서 한줄 읽기
	{
		++no;
		std::string word;
		std::istringstream iss(s);

		while (iss >> word) // 문장을 단어별로 분리
		{
			indexMap[word].push_back(no);
		}
	}
	//=========================================
	// map 의 내용 출력
	// auto p = indexMap.begin();
	// => p 는 반복자 이므로 "pair의 포인터" 처럼 생각

	for (const auto& p : indexMap)
	{
		// p의 타입은 ??
		// => 반복자가 아니라 indexMap 의 요소를 꺼낸 것.. 
		// => pair 의 포인터가 아니라, pair(참조)..
		std::cout << p.first << " : "; // 단어
		
		for (auto e : p.second) // list 모든 항목 꺼내기
			std::cout << e << ", ";

		std::cout << std::endl; // 개행
	}
}
// readme.txt 파일 하나 구해서 현재 폴더(DAY4) 안에 넣어두고,
// 실행해 보세요


