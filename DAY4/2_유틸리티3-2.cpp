#include <iostream> // ǥ�� ����� ��Ʈ��
#include <fstream>  // ȭ�� ��Ʈ��
#include <sstream>  // �޸�(��Ʈ��)��Ʈ��
#include <string>

int main()
{
	std::ostringstream oss; // �޸� ��� ��Ʈ�� 
	oss << "hello";


	std::istringstream iss("to be or not to be"); 

	std::string s;

//	std::cin >> s;	// ǥ�� �Է¿��� �� �ܾ� �Է�
//	iss >> s;		// iss �� ���� ���ڿ����� �Ѵܾ� �Դϴ�.

	// �Ʒ� �ڵ��� �ǹ̸� ������ ������ - C����� strtok()
	// => ������ �ܾ�� �����ϴ� �ڵ� 
	while (iss >> s)
		std::cout << s << std::endl;
}






