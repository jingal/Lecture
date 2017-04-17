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
	virtual void f1(int) {}		//���� �߸�..
	virtual void f2() {}		// const �Լ�
	virtual void fa3() {}		// �̸� �߸�
	virtual void f4() {}		// f4�� �����Լ� �ƴ�
};
*/

/*
class Derived : public Base
{
public:
	// �����ϸ� override�� �ٿ���
	virtual void f1(int) override {}		//���� �߸�..
	virtual void f2() override {}		// const �Լ�
	virtual void fa3() override final{}		// �̸� �߸�
	virtual void f4() override {}		// f4�� �����Լ� �ƴ�
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
	// �����ϸ� override�� �ٿ���
	virtual void f1() {}		//���� �߸�..
	virtual void f2() override {}		// const �Լ�
	virtual void f3() override final {}		// �̸� �߸�
};


class Derived2 : public Derived
{
public:
	// �����ϸ� override�� �ٿ���
	void f1() override {}		//���� �߸�..
	void f2() {}		// const �Լ�
	virtual void f3() override {}		// �̸� �߸�	
};

int main()
{
	
}