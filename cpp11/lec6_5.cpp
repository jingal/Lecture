#include <iostream>
#include <type_traits>


using namespace std;

///////////////////////////////////////////////////////////////////////////
//	noecept
///////////////////////////////////////////////////////////////////////////

/*
void foo throw() //c++ 98에서 예외 없음을 나타낸다.
{

}
*/

//void foo() noexcept //C++ 11, 최적화 시 좀더 최적화 가능
void foo()
{

}


int main()
{
	foo();

	Test t;
	move_if_noexcept(t);
}