#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	user define literal
///////////////////////////////////////////////////////////////////////////

class Meter
{
	int value;
public:
	Meter(int n) : value(n) {}
};


// 정수형태 리터럴을 받으려면 long long type으로 받아야함
// char 형태일 경우 char* 형태로
Meter operator""_m(unsigned long long a)
{
	return Meter(static_cast<int>(a));
}

int main()
{
	//literal이 무엇인지 정확하게 알려주기 위해서 추가
	// _가 추가된 이유는 표준과 충돌을 피하기 위해서
	Meter m = 3_m;		//operator ""m(int a)

	float a = 3.4f;
	long b = 4l;


}
