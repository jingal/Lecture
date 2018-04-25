//5_RTTI3 - 35 page

#include <iostream>
#include <string>
using namespace std;

// 규칙 1. 모든 클래스에는 자신의 정보를 담은 static 변수가
//			있어야 한다.
// 규칙 2. (1)의 static 변수를 반환하는 가상함수가 있어야 한다.
//			C++표준의 typeid역활

// 위 규칙을 생성하는 매크로를 제공합니다.
#define DECLARE_META_INTERFACE(classname)	\
	static const string description;		\ 
	virtual const string& getInterfaceDescritption();

// 구현부를 제공하는 매크로
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