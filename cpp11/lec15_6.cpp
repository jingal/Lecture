#include <iostream>
#include <type_traits>
#include <typeinfo>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	nullptr ¸¸µé±â
///////////////////////////////////////////////////////////////////////////

void foo(int n) { cout << "int" << endl; }
void foo(int* p) { cout << "int*" << endl; }
void goo(char* n) { cout << "goo" << endl; }

struct xnullptr_t
{
	//operator int*() { return 0; }
	template<typename T> operator T*() { return 0; }
};
xnullptr_t  xnullptr;


int main()
{
	foo(xnullptr);
	goo(xnullptr);
}




/*
int main()
{
cout << typeid(34).name() << endl;

cout << typeid(nullptr).name() << endl;			//nullptr_t
}
*/

