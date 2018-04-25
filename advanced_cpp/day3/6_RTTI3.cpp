//5_RTTI3 - 35 page

#include <iostream>
#include <string>
using namespace std;

// ��Ģ 1. ��� Ŭ�������� �ڽ��� ������ ���� static ������
//			�־�� �Ѵ�.
// ��Ģ 2. (1)�� static ������ ��ȯ�ϴ� �����Լ��� �־�� �Ѵ�.
//			C++ǥ���� typeid��Ȱ

// �� ��Ģ�� �����ϴ� ��ũ�θ� �����մϴ�.
#define DECLARE_META_INTERFACE(classname)	\
	static const string description;		\ 
	virtual const string& getInterfaceDescritption();

// �����θ� �����ϴ� ��ũ��
#define IMPLEMENT_META_INTERFACE(classname, desc)						\
	const string classname::description = #desc;		\
	const string& classname::getInterfaceDescritption()		\
	{ return classname::description; }


class LedService
{
public:
	DECLARE_META_INTERFACE(LedService)
};

IMPLEMENT_META_INTERFACE(LedService, "com.lg.LedService")

int main()
{
	LedService* p = new LedService;
	cout << p->getInterfaceDescritption() << endl;
}