// 6_callableobject10

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	// 람다표현식 활용
	// 1. 함수인자로 전달, 대부분 사용(거의 70% 정도로 사용)
	for_each(x, x + 10, [](int a) {});

	// 2. 바로 호출 (거의사용 안함)
	[]() {cout << "hello" << endl; }();

	// 3. 변수에 담아서 함수처럼 사용
	int n1 = 0;
	auto f = [n1](int a, int b) {return a + b; };
				// class xxx, xxxx();

	cout << f(1, 2) << endl;	//3

	cout << sizeof(f) << endl;
}

// 안드로이드코드/base/scopedguard_test.cpp