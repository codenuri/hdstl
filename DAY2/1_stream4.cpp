#include <iostream>
#include <iterator>
#include <list>
#include <fstream>

int main()
{
	// ���� C++ ���� ������� �Ʒ� ó�� ��ü�� �����մϴ�.
	std::ofstream fout("a.txt"); // ��� ����
	std::ifstream fin("1_stream3.cpp"); // �Է�����

	// ���� ������ cout, cin �� �����մϴ�.
	fout << 10 << ", " << 3.4;  // ���Ͽ� "10, 3.4" ����

	std::string s;
	fin >> s; // ���Ͽ��� �Ѵܾ� �б�
}