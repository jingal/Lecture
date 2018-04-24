//4_�������4

#include <iostream>
#include <vector>
using namespace std;

// CRTP (Curiosly Recurring Template Pattern
// ��� Ŭ������ ���ø��ε�, �Ļ� Ŭ���� ���鶧 ���ڷ�
// �ڽ��� �̸��� �����ϴ� �ڵ�
// ���� ���� �ڵ忡�� �̷��� ������� Ŭ������ �̸��� 
// ����� �� �ִ�.
template<typename T> class RefCounted
{
	int m_refCount = 0;
public:
	void ref() { m_refCount++; }
	void deref()
	{
		// �ٽ� : delete �Ҷ� this�� �Ļ� Ŭ���� Ÿ������
		//		ĳ�����ؼ� ����.
		if (--m_refCount == 0) 
			delete static_cast<T*>(this);
	}

protected:	
	// ���� �Ҹ��ڸ� ������� ����.
	// �����Լ��� ������尡 ��� �Ļ�Ŭ������ �ִ� ���� 
	// �ȴٴ� �ǵ�
	~RefCounted() { cout << "~RefCounted" << endl; }
};

class Truck : public RefCounted<Truck>
{
public:
	~Truck() { cout << "~Truck" << endl; }
};

int main()
{
	Truck* p = new Truck;

	p->ref();
	p->deref();
}