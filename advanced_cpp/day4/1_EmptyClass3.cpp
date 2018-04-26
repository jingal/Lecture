//1_EmptyClass3 - 73 page EBCO

#include <iostream>
using namespace std;


// 결국 표준의 operator new는 아래 처럼 실패를 처리합니다.
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

	return p;			// 실패시 0 리턴
}



int main()
{
	//1. operator new로 메모리 할당
	//2. 생성자 호출

	int* p = new int;				// 인자가 한개인 경우

	int* p = new("AA", 2) int;		// 인자가 여러개인 경우

							
}