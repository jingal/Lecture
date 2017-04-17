#include <iostream>
#include <type_traits>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	nullptr #1 - 0의 문제점
///////////////////////////////////////////////////////////////////////////

void goo(char*p) { cout << "goo" << endl; }

void foo(int n) { cout << "int" << endl; }
void foo(void* n) { cout << "void*" << endl; }

int main()
{
	foo(0);				// int
	foo((void*)0);		// void*


#ifdef __cplusplus
#define NULL 0
#else
#define NULL (void*)0	//C style
#endif

	foo(NULL);			//void* int

	goo(NULL);			//void* => char*로 암시적 형변환 필요.. C허용 C++안됨
}