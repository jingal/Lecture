#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	initializer_list
///////////////////////////////////////////////////////////////////////////

//initializer_list<int> : braced-init-list의 요소를 시작과 끝 (갯수)를 가리키는 클래스

int main()
{
		//VC++ : int *first, *last;
		//g++ : int *first, count

	initializer_list<int> s = { 12,3,4,5,6,7,8,9,10 };

	auto p1 = s.begin();
	auto p2 = s.end();

	*p1 = 10; //error, 읽기만 가능, 함수의 인자로 많이 사용
}
