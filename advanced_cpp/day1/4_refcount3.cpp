//4_�������3

#include <iostream>
#include <vector>
using namespace std;

// ��������� å������ ��� Ŭ����
class RefCounted
{
	int m_refCount = 0;
public:
	void ref() { m_refCount++; }
	void deref()
	{
		//RefCounted* const this
		if (--m_refCount == 0) delete this;
	}

protected:
	// ��� Ŭ������ �Ҹ��ڴ� ���� �Ҹ��� �̾�� �Ѵ�.
	virtual ~RefCounted() { cout << "~RefCounted" << endl; }
};

//Truck�� ��������� �����ϰ� �ʹ�.
class Truck : public RefCounted
{
	~Truck() { cout << "~Truck" << endl; }
};

int main()
{
	Truck* p = new Truck;

	p->ref();
	p->deref();

	// RefCoutef* this = new Truck;
	// delete this; //�޸� �����ؼ� �Ҹ��� ȣ��
}