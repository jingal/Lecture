#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	override
///////////////////////////////////////////////////////////////////////////
/*
class Base
{
public:
	virtual void f1(double) {}
	virtual void f2() const {}
	virtual void f3() {}
	void f4() {}
};


class Derived : public Base
{
public:
	virtual void f1(int) {}		//인자 잘못..
	virtual void f2() {}		// const 함수
	virtual void fa3() {}		// 이름 잘못
	virtual void f4() {}		// f4는 가상함수 아님
};
*/

/*
class Derived : public Base
{
public:
	// 가능하면 override를 붙여라
	virtual void f1(int) override {}		//인자 잘못..
	virtual void f2() override {}		// const 함수
	virtual void fa3() override final{}		// 이름 잘못
	virtual void f4() override {}		// f4는 가상함수 아님
};
*/

class Base
{
public:
	virtual void f1() {}
	virtual void f2() {}
	virtual void f3() {}	
};


class Derived : public Base
{
public:
	// 가능하면 override를 붙여라
	virtual void f1() {}		//인자 잘못..
	virtual void f2() override {}		// const 함수
	virtual void f3() override final {}		// 이름 잘못
};


class Derived2 : public Derived
{
public:
	// 가능하면 override를 붙여라
	void f1() override {}		//인자 잘못..
	void f2() {}		// const 함수
	virtual void f3() override {}		// 이름 잘못	
};

int main()
{
	
}