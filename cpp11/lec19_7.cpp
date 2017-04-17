#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
#include <typeinfo>
//#include <vector>
#include <boost/type_index.hpp>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	19강 6.Reference collapse
///////////////////////////////////////////////////////////////////////////

//Reference Collapse

typedef int& LREF;
typedef int&& RREF;

int main()
{
	//C++ 표준의 RTTI 기술..
	//cout << typeid(LREF&).name() << endl;
	//cout << typeid(LREF&&).name() << endl;
	//cout << typeid(RREF&).name() << endl;
	//cout << typeid(RREF&&).name() << endl;

	//boost 를 사용한 타입 조사
	cout << type_id_with_cvr<LREF&>().pretty_name() << endl;
	cout << type_id_with_cvr<LREF&&>().pretty_name() << endl;
	cout << type_id_with_cvr<RREF&>().pretty_name() << endl;
	cout << type_id_with_cvr<RREF&&>().pretty_name() << endl;
}

/*
int main()
{
	int v1 = 10;

	LREF lr = v1;		//int&
	RREF rr = 10;		//int&&

	LREF& r1 = v1;		//int& & => int&
	LREF&& r2 = v1;	//int& && => int&
	RREF& r3 = v1;		//int&& & => int&
	RREF&& r4 = 10;	//int&& && => int&&
}
*/