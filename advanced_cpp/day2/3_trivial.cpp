//3_trivial

#include <iostream>
using namespace std;

// trivial 생성자 : 생성자가 하는 일이 없는 것

// 1. 가상함수가 없고
// 2. 기반 클래스가 없거나, 기반 클래스의 생성자가 trivial 
// 3. 객체형 멤버가 없거나, 객체형 멤버의 생성자가 trivial하고
// 4. 사용자가 만든 생성자가 없을 때

// 생성자는 trivial 하다.

class Base
{

};

// Derived의 생성자는 디폴트이긴 하지만 하는 일이 있음
class Derived : public Base
{
public :
	// 가상함수가 있으면 디폴트생성자에서 
	// 가상함수 테이블 포인터 초기화 코드를 수행하게 됩니다.
	// "inside C++ object" "스탠리 립만"
	virtual void foo() {}
};


int main()
{
	// Derived 는 생성자가 trivial 할까요?
	Derived *p = static_cast<Derived*>(
					operator new(sizeof(Derived)));

	// 생성자만 호출하는 new : placement new 라고 합니다. (위치지정 new)
	new(p) Derived;
	p->foo();
}