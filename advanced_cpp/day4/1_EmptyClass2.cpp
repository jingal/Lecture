//1_EmptyClass2 - 73 page EBCO

#include <iostream>
using namespace std;

int main()
{

	// 다음중 잘못된 곳음
	//int* p = new int;		// 메모리 할당 실패시 0이 아니고 
							// std::bad_alloc 예외 발생
							// 0체크 말고 try catch (bad alloc)을 사용해야 함.

	// 실패시 예외 대신 0을 반환해 달라.
	int* p = new(nothrow) int;

	if (p == 0)
	{
		//...
	}

	delete p;
}


