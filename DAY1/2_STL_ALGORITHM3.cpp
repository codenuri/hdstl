#include <iostream>

// Step 3. �˻� ��� Ÿ���� �Ϲ�ȭ
// => char* ��� "���ø� ���"
// => �Լ� �̸� ���� : "strchr" -> "find"

// ��� Ÿ���� �迭���� [first, last) ���̿��� �����˻�����
template<typename T> 
T* find(T* first, T* last, T c)
{
	while (first != last && *first != c)
		++first;

	return first == last ? nullptr : first;
}

int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	double* p = find(x, x + 10, 5.0);

	if (p == 0)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}