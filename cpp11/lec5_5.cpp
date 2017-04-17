#include <iostream>
#include <cstdio>

using namespace std;

// Safe bool Idioms ==> 변환의 위험성

//void dummy_function() {}
class myistream
{
public:
	bool fail() { return false; }
	void operator>> (int n) {}
	
	//1. bool로 변환하자.
	//operator bool() { return !fail(); }

	//2. 쉬프트 연산이 안되는 타입으로 변환하자. --> 포인터로 변환하자
	//operator void*() { return fail() ? 0 : this; }


	//3. delete가 되지 않는 포인터를 사용하자.
	// 함수 포인터
	//typedef void(*PF)();
	//operator PF() { return fail() ? 0 : &dummy_function; }

	//4. 멤버함수 포인터로의 변환.. 구글에서 c++ idioms, 부스트의 trybool이 사용하는 기법
	void dummy_function() {}
	typedef void(myistream::*PF)();
	operator PF() { return fail() ? 0 : &myistream::dummy_function; }
};

myistream mycin;

int main()
{
	int n = 0;
	mycin >> n;

	if (mycin) 
	{

	}

	//mycin << n;		//error가 발생하지 않음, bool 변환이 되기 때문에 bool로 되고 쉬프트 연산을 해버리게 됨

	//delete mycin;		// C++ 98에서 delete cin이 컴파일 에러가 없다..

	void(*f)() = mycin;	//ok..
}



/*
int main()
{
	int n = 0;

	cin >> n;		//'a'

	if (cin.fail())
	{
		cout << "입력 실패.." << endl;
	}

	if (cin)	// if (bool, 정수, 실수, 포인터) , 임의의 객체가 if문에 들어갈 수 있는 이유
				//									c++98까지 : cin.operator void*()
	{
		cout << "입력 성공.." << endl;
	}
}
*/