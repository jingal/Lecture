// 4_move3 - 133 page

#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

struct Test
{
	int* p = 0;

	Test() {
		p = new int[100];
	}

	Test(const Test& t)
	{
		cout << "복사 생성자" << endl;
		p = new int[100];
		memcpy(p, t.p, sizeof(int) * 100);
	}
	
	// 일반함수도 왠만하면 noexept 붙이는 것이 좋다.
	// 예외가 없음을 표현
	// f() nothrow(int) : int 타입의 예외가 발생할 수 있음
	// f() nothrow() : C++ 98
	// f() noexecpt : C++ 11

	Test(Test&& t) noexcept
	{
		cout << "move 생성자" << endl;
		p = t.p;
		t.p = 0;
	}

	void foo() const noexcept {}

	~Test() { delete[] p; }
};

void foo() noexcept {}

int main()
{
	vector<Test> v(2);
	v.resize(4); // 2개짜리 버퍼를 4개로 변경해야 합니다.

	//예외 조사
	//1.생성자, 복사, 소멸자등
	is_nothrow_default_constructible<Test>::value;

	//foo함수의 예외 가능성 조사
	// unevaluated expression
	bool b2 = noexcept(foo());
}