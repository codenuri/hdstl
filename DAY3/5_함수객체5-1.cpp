// 5_�Լ���ü5-1
#include <iostream>
#include <vector>
#include <algorithm>

/*
bool foo(int n)
{
	return n % k == 0; // error. ���⼭ k �� ����Ҽ� �����ϴ�.
}
*/

class IsDivide
{
	int value;
public:
	IsDivide(int n) : value(n) {}

	bool operator()(int n) // �� �Լ� ������ ���ڰ� �Ѱ��� �Լ� ó�� ��밡��
	{
		return n % value == 0;
	}
};

int main()
{
	int k = 4;
	std::vector<int> v = { 1,9,3,4,5,6,7,8,9,10 };
	
	IsDivide f(k);	// �Լ� ó�� ��밡���� ��ü�� ���鶧
					// main �� ���������� "k" �� ����
	bool b = f(10); // 10 % k == 0 ����. �� 4�� ����ΰ� ����
					// f.operator()(10)
	auto ret2 = std::find_if(v.begin(), v.end(), f );

	// �Լ� ��ü ����. �ѹ��� ����Ѵٸ� "�ӽð�ü"���·� �����ص� �˴ϴ�.
	// "Ŭ�����̸�()" : ��ü�� �����ϴ� ǥ��� �Դϴ�.
	auto ret3 = std::find_if(v.begin(), v.end(), IsDivide(k) );
}
// �ٽ�
// �Ϲ� �Լ��� ���¸� ������ ������
// �Լ� ��ü�� ���¸� ������ �ֽ��ϴ�.(��� ����Ÿ�� �ִٴ� �ǹ�)
// �׷���, ���� IsDivide ó��. main ���� ����ϴ�, ���������� �Լ� ��ü�� �����ؼ�
// ��� �����մϴ�
// => "Ŭ����"��� �մϴ�.