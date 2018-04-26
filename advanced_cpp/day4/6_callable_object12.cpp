// 6_callable_object12

#include <iostream>
#include <algorithm>
using namespace std;


int main()
{	

	// 한번 초기화 된 람다변수는 변경 불가능
	auto f1 = [](int a, int b) { return a + b; };
	auto f2 = [](int a, int b) { return a + b; };

	//f1과 f2는 같은? 다른? 타입
	cout << typeid(f1).name() << endl;
	cout << typeid(f2).name() << endl;

	//f1 = [](int a, int b) { return a + b; };	// error, 다른 타입이므로 대입 안됨

	int n1 = 0;
	decltype(n1) n2;		//ok... int n2;

	//decltype(f1) f3;			// error, Clouser에는 Default 생성자가 삭제되어 있음
	decltype(f1) f3(f1);		// ok,컴파일러가 만들어주는 클롲에는 복사 생성자가 있기 때문에 OK

	int(*f)(int, int) = f1;		//ok. 함수 포인터로 변환 가능
								// f1.operator int(*)(int, int)로 변환을 허용해주는 변환연산자 함수 제공
}
// cppreference.com "lambda" 검색
// https://isocpp.org/