#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <fstream>
#include "show.h"


int main()
{
	std::vector<std::string> v;
	std::ifstream f("11_���������̳�6.cpp"); // ���� �����̸�

	std::string s;

	while (std::getline(f, s))
		v.push_back(s);
	//----------------------------



	//-------------------------------------
	for (auto& n : v)
		std::cout << n << std::endl;
}


