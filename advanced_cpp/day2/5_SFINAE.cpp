//5_SFINAE - 215 page


struct A
{
	//static int DWORD;
	typedef int DWORD;
};
int p = 0;

template<typename T>
void foo(T a)
{
	// A::DWORD
	// Ŭ�����̸�::static ��� ����
	typename T::DWORD* p;			//DWORD Ÿ������ �ؼ��� �޶�.
									//T������ ���� ���� Ÿ������ �ؼ��� �޶�.

	//T::DWORD* p;					//�� ���� �ؼ��� ������
									// DWORD�� �����

	// 1. �� : DWORD�� static �����ε� ���ϱ� p�ϰ� �ִ�.
	// 2. Ÿ�� : DWORD�� ���� Ÿ���ε� ������ ���� p�� ����
}

int main()
{
	A a;
	foo(a);
}