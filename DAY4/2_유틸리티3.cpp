#include <iostream> // ǥ�� ����� ��Ʈ��
#include <fstream>  // ȭ�� ��Ʈ��
#include <sstream>  // �޸�(��Ʈ��)��Ʈ��
#include <string>

// C++ ǥ�ؿ� �Ʒ� ó�� �Ǿ� �ֽ��ϴ�.
/*
namespace std
{
	// 1. C++ ǥ�� ����� ��Ʈ�� - <iostream>
	class ostream {};
	ostream cout;

	// 2. C++ ���� ����� ��Ʈ�� - <fstream>
	class ofstream {}; 
	class ifstream {};

	// 3. C++ �޸� ����� ��Ʈ�� - <sstream>
	class ostringstream {};
	class istringstream {};
}
*/
int main()
{
	// 1. ǥ�� ��� ��ü�� �̹� "cout" �� �����Ǿ� �����Ƿ� ����ϸ� �˴ϴ�.
	std::cout << "hello";

	// 2. ���� ������� �ʿ��ϸ� "���� ��Ʈ��"��ü�� ����� ����ϸ� �˴ϴ�
	std::ofstream fout("a.txt");

	fout << "hello"; // cout �� ������ �����մϴ�.

	// 3. �޸�(���ڿ�)���
	std::ostringstream oss;
	oss << "hello";

}
