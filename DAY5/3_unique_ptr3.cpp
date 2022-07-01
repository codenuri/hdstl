#include <memory>
#include <iostream>
// shared_ptr�� ��쿡�� �Լ���ü ������ �����Ѱ���? 
// => ��, ������ 2��° ���ڷ� ������ �˴ϴ�.
// 
// �׸��� Freer�� operator()�� inline�� �ƴ� �Ϳ��� ������ �������?
// => inline ǥ�� ���ص�, ��� �Լ��� ���� �ȿ� �����ϸ� �ڵ����� inline�˴ϴ�.

struct Freer
{
	inline void operator()(void* p)
	{
		free(p);
	}
};
// �����ڸ� template ���ڷ� ������ ������Ұ� ��� �˴ϴ�.
template<typename T, typename Dx>
class unique_ptr
{
	T* obj;
public:
	~unique_ptr()
	{
		Dx d; // ������ ��ü�� �����ؼ�
		d(obj); // ����.. 
				// �����ڸ� ������ �������� �ʰ� �ֽ��ϴ�.
	}
};


int main()
{
	// ������ ����
	// shared_ptr : �������� 2��° ���ڷ� ����
	// unique_ptr : ���ø� 2��° ���ڷ� �Լ� ��ü ����
	std::shared_ptr<int>        sp1(static_cast<int*>(malloc(sizeof(int)), free);
	std::unique_ptr<int, Freer> up1(static_cast<int*>(malloc(sizeof(int)));

	std::shared_ptr<int> sp2(new int);
	std::unique_ptr<int> up2(new int);


	// shared_ptr vs unique_ptr
	// shared_ptr�� �����ڸ� �����ص� ���� Ÿ�� �Դϴ�. => ���� �����̳ʿ� ������ ����
	// unique_ptr�� �����ڸ� �����ϸ� �ٸ� Ÿ�� �Դϴ�. 

	// shared_ptr �� ���� ��ü�� �����ڸ� �����ߴٰ� ����մϴ�.




	// new �� �迭�� �Ҵ��ϴ� ���

	std::unique_ptr<int> up1(new int);     // ok �Ҹ��ڰ� delete
//	std::unique_ptr<int> up2(new int[10]); // ����.. 
	std::unique_ptr<int[]> up2(new int[10]); // ok.. C++14 ���� ����
								// C++14 �������� ���ø� ���ڷ� �����ڸ� ����

	std::shared_ptr<int[]> sp(new int[10]); // C++17���� ����

	// ��, new int[10] ������ �ʿ��ϸ� "����Ʈ������ ����"
	// vector�� ���� ����� ������
	// std::vector<int> v(10);
}