#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <unordered_map>

int main()
{
	std::ifstream fin("4_map2.cpp");

//	std::map<std::string, std::list<int>> indexMap; 
	std::unordered_map<std::string, std::list<int>> indexMap;

	std::string s;
	int no = 0;

	while (std::getline(fin, s)) 
	{
		++no;
		std::string word;
		std::istringstream iss(s);

		while (iss >> word) 
		{
			indexMap[word].push_back(no);
		}
	}
	//=========================================

	for (const auto& p : indexMap)
	{
		std::cout << p.first << " : "; 

		for (auto e : p.second) 
			std::cout << e << ", ";

		std::cout << std::endl;
	}
}
