//1_EmptyClass4 - 73 page EBCO

#include <iostream>
using namespace std;


/*
// �ᱹ ǥ���� operator new�� �Ʒ� ó�� ���и� ó���մϴ�.
void* operator new(size_t sz)
{
	cout << "my new : " << sz << endl;
	void *p = malloc(sz);
	if (p == 0)
		throw std::bad_alloc();

	return p;
}

void* operator new(size_t sz, const char* s, int n)
{
	cout << "my new2 : " << sz << endl;
	void *p = malloc(sz);
	if (p == 0)
		throw std::bad_alloc();

	return p;
}

// empty classs
// ���ø� ���ڳ�, �Լ� �����ε����� ����ϱ� ���ؼ� 
// �θ� ���ȴ�.

struct nothrow_t {};
nothrow_t nothrow;

void* operator new(size_t sz, nothrow_t)
{
	cout << "my new2 : " << sz << endl;

	void *p = malloc(sz);

	return p;			// ���н� 0 ����
}
//#define nothrow 
*/

int main()
{
	//1. operator new�� �޸� �Ҵ�
	//2. ������ ȣ��

	int* p = new int;				// ���ڰ� �Ѱ��� ���

	//int* p = new("AA", 2) int;		// ���ڰ� �������� ���
	int* p = new(nothrow) int;		// ���ڰ� �������� ���


}