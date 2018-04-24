//4_�������5

#include <iostream>
#include <vector>
using namespace std;

template<typename T> class RefCounted
{
	// mutable : ��� �Լ� �ȿ����� ���� ������ �� �ְ� �Ѵ�.
	// ��� �Լ� ������ ����ϰ� �Ǹ� mutable Ű���带 ���� 
	// ����ϰ� �˴ϴ�.
	mutable int m_refCount = 0;

public:
	void foo()
	{
		// this : RefCounted* const this
		// this->�������Ÿ = 10;
	}

	void goo() const
	{
		//this : const RefCounted* const this
		//this->�������Ÿ = 10; //error
	}
	void ref() const { m_refCount++; }
	void deref() const
	{
		if (--m_refCount == 0)
			//delete static_cast<T*>(this);		//error
			//delete static_cast<T*>(
			//	const_cast<RefCounted*>(this));		//�ڱ��ڽſ� ���ؼ� const_cast ġȯ
			delete static_cast<const T*>(this);		//error
	}

protected:
	~RefCounted() { cout << "~RefCounted" << endl; }
};

class Truck : public RefCounted<Truck>
{
public:
	~Truck() { cout << "~Truck" << endl; }
};

int main()
{
	const Truck* p = new Truck;

	p->ref();
	p->deref();
}