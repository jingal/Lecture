//2_rvalue3

#include <iostream>
using namespace std;

// 이 규칙이 중요합니다. 꼭 외워 두세요.
void foo(int& a) { cout << "int&" << endl; }
void foo(const int& a) { cout << "const int&" << endl; }
void foo(int&&a) { cout << "int&&" << endl; }


int main()
{
	int n = 10;
	foo(n);				//1번(int&) 호출, 없으면 2번(const int&) 호출
	foo(10);			//3번(int&&)호출, 없으면 2번 호출

	int& r = n;			
	foo(r);				//1번(int&) 호출, 없으면 2번(const int&) 호출

	int&& r2 = 10;		// 10은 rvalue
						// 이름이 있음, r2 는 lvaule
						// "named rvalue reference is lvalue"
	foo(r2);			//1번(int&) 호출
	foo(static_cast<int&&>(r2));		//3번 호출
}