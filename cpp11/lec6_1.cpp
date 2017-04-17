#include <iostream>
#include <cassert>

using namespace std;


//static_assert(sizeof(double) > 8, "error, assert failed");

void foo(int age)
{
	static_assert(age > 0, "failed");	// error, 런타임은 체크 안됨, 조건식은 컴파일 시간에 결정되어야 한다.
}

int main()
{
	static_assert(sizeof(double) > 8, "error, assert failed");
}



/*
void foo(int age)
{
	//인자를 사용하기 전에 유효성을 먼저 확인한다.
	assert(age > 0);

	// age 사용...
	//
}

int main()
{
	foo(0);
}
*/