// 5_excetion 

#include <iostream>
using namespace std;

// C++ 표준에 이미 예외를 위한 기반 클래스 제공
/*
class exception
{
public:
	virtual const char* what()
	{
		return "unknown exception";
	}
};*/

struct memory_exeption : public exception
{
	virtual const char* what() const override
	{
		return "memory error";
	}
};

void foo()
{
	if (1) //실패
		throw memory_exeption();
		// 임시 변수로 던지지만 exception 에서는 예외적으로 참조로 받을 수 있음
}

int main()
{
	try
	{
		foo();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}
