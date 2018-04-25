// 6_enable_if3 - 77 page

#include <iostream>
#include <type_traits>
using namespace std;

// type traits : 타입의 속성을 조사하는 라이브러리
//					<type_traits>
//					조사할 속성<타입>::value
//					is_abstact<T>::value
//					

/*
template<typename T> void foo(T a)
{
	static_assert(!is_pointer<T>::value, "error");
	//...
}
*/
// 조건을 만족하지 못할때..
// 에러가 아니라 후보군에서 제외 (코드생성 안함)
// SFINAE 기술이 필요하다.


template<typename T> 
typename enable_if<!is_pointer<T>::value, void>::type foo(T a)
{	
	//...
}


void foo(...) { cout << "디폴트 처리" << endl; }

int main()
{
	int n = 10;
	foo(&n);
}
