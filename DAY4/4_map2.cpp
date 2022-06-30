#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <algorithm>

int main()
{
	std::ifstream fin("4_map2.cpp"); // ���� �ϳ� ���� �μ���

	std::map<std::string, std::list<int>> indexMap; // �ٽ� �ڷᱸ��
	std::string s;
	int no = 0;

	while (std::getline(fin, s)) // ���Ͽ��� ���� �б�
	{
		++no;
		std::string word;
		std::istringstream iss(s);

		while (iss >> word) // ������ �ܾ�� �и�
		{
			indexMap[word].push_back(no);
		}
	}
	//=========================================
	// map �� ���� ���
	// auto p = indexMap.begin();
	// => p �� �ݺ��� �̹Ƿ� "pair�� ������" ó�� ����

	for (const auto& p : indexMap)
	{
		// p�� Ÿ���� ??
		// => �ݺ��ڰ� �ƴ϶� indexMap �� ��Ҹ� ���� ��.. 
		// => pair �� �����Ͱ� �ƴ϶�, pair(����)..
		std::cout << p.first << " : "; // �ܾ�
		
		for (auto e : p.second) // list ��� �׸� ������
			std::cout << e << ", ";

		std::cout << std::endl; // ����
	}
}
// readme.txt ���� �ϳ� ���ؼ� ���� ����(DAY4) �ȿ� �־�ΰ�,
// ������ ������


