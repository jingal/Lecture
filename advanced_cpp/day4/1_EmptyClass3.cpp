//1_EmptyClass3 - 73 page EBCO

#include <iostream>
using namespace std;


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

void* operator new(size_t sz, const char* s, int n)
{
	cout << "my new2 : " << sz << endl;

	void *p = malloc(sz);

	return p;			// ���н� 0 ����
}



int main()
{
	//1. operator new�� �޸� �Ҵ�
	//2. ������ ȣ��

	int* p = new int;				// ���ڰ� �Ѱ��� ���

	int* p = new("AA", 2) int;		// ���ڰ� �������� ���

							
}