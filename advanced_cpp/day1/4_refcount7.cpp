//4_�������6

#include <iostream>
#include <vector>
using namespace std;

// 237. thintemplate
// ���ø��� ���鶧 T�� �������� ���� ����� 
// ���ø��� �ƴ� ��� Ŭ������ ���� ��������.

class RefCountedBase
{
protected:
	mutable int m_refCount = 0;

public:
	void ref() const { ++m_refCount; }
	void derefBase() const
	{

	}

	int refCount() const { return m_refCount; }
};

template<typename T> class RefCounted : public RefCountedBase
{
public:
	void deref() const
	{
		derefBase();
		if (--m_refCount == 0) delete static_cast<const T*>(this);
	}

protected:
	~RefCounted() { cout << "~RefCounted" << endl; }

};

class Truck : public RefCounted<Truck>
{
public:
	~Truck() { cout << "~Truck()" << endl; }
};


// ��ü�� ��������� �����ϴ� ����Ʈ������
template<typename T> class sp
{
	T* obj;

public:
	sp(T* p = 0) : obj(p) { if (obj) obj->ref(); }
	sp(const T& p) : obj(p.obj) { if (obj) obj->ref(); }

	~sp() {
		if (obj) obj->deref();
	}

	//����Ʈ �������� �⺻ ->�� *
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};


int main()
{
	//sp<Truck> p1 = new Truck;
	sp<Truck> p1 (new Truck);
	sp<Truck> p2 = p1;

}

/*
int main()
{
	Truck* p1 = new Truck;
	p1->ref();

	Truck* p2 = p1;
	p2->ref();

	p1->deref();
	p2->deref();
}
*/