#include <iostream>
#include <type_traits>


using namespace std;

///////////////////////////////////////////////////////////////////////////
//	noecept
///////////////////////////////////////////////////////////////////////////

/*
void foo throw() //c++ 98���� ���� ������ ��Ÿ����.
{

}
*/

//void foo() noexcept //C++ 11, ����ȭ �� ���� ����ȭ ����
void foo()
{

}


int main()
{
	foo();

	Test t;
	move_if_noexcept(t);
}