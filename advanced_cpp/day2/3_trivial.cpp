//3_trivial

#include <iostream>
using namespace std;

// trivial ������ : �����ڰ� �ϴ� ���� ���� ��

// 1. �����Լ��� ����
// 2. ��� Ŭ������ ���ų�, ��� Ŭ������ �����ڰ� trivial 
// 3. ��ü�� ����� ���ų�, ��ü�� ����� �����ڰ� trivial�ϰ�
// 4. ����ڰ� ���� �����ڰ� ���� ��

// �����ڴ� trivial �ϴ�.

class Base
{

};

// Derived�� �����ڴ� ����Ʈ�̱� ������ �ϴ� ���� ����
class Derived : public Base
{
public :
	// �����Լ��� ������ ����Ʈ�����ڿ��� 
	// �����Լ� ���̺� ������ �ʱ�ȭ �ڵ带 �����ϰ� �˴ϴ�.
	// "inside C++ object" "���ĸ� ����"
	virtual void foo() {}
};


int main()
{
	// Derived �� �����ڰ� trivial �ұ��?
	Derived *p = static_cast<Derived*>(
					operator new(sizeof(Derived)));

	// �����ڸ� ȣ���ϴ� new : placement new ��� �մϴ�. (��ġ���� new)
	new(p) Derived;
	p->foo();
}