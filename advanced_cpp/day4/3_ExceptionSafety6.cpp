// 3_ExceptionSafety6 - 197 page

#include <iostream>
#include <memory> 
using namespace std;

int foo() { return 1; }
void goo(shared_ptr<int> p, int n) {}

int main()
{
	//shared_ptr<int> p(new int);		//c++ 표준 스마트 포인터

	// 스마트 포인터 사용시 Raw Pointer를 2개 이상의
	// 스마트 포인터에 넣으면 안된다.
	//int* p1 = new int;
	//shared_ptr<int> sp1(p1);
	//shared_ptr<int> sp2(p1);

	// RAII를 해야한다. 즉, sp를 만들때 new
	shared_ptr<int> sp1(new int);

	// shared_ptr을 만들어서 보내보세요.
	// 아래 코드의 문제점은 ?
	// 아래의 순서로 실행되는 경우도 있을 수 있습니다.
	// 1. new int 성공
	// 2. foo 호출 => 여기서 예외가 나온다면
	// 3. shared_ptr 만들기
	// 4. goo 호출

	//goo(shared_ptr<int>(new int), foo());

	// make_shared<int>() : int 메모리를 할당하고 
	//						관리하는 shared_ptr을 만들어 달라.
	shared_ptr<int> sp3 = make_shared<int>();
	goo(make_shared<int>(), foo());
}