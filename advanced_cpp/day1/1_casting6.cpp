//1_casting6.cpp - å 7 page addressof
#include <iostream>
using namespace std;

int main()
{
	const int c = 10;

	//int* p = static_cast<int*>(&c);		//error
	//int* p = reinterpret_cast<int*>(&c);	//error

	//���� Ÿ���� const �Ӽ��� �����Ҷ� ���.
	int* p = const_cast<int*>(&c);			//ok

	*p = 20;

}

// static_cast
// dynamic_cast
// reinterpret_cast
// const_cast

