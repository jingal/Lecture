//client10
#include <iostream>
#include <Windows.h>		//DLL load함수

using namespace std;

#include "ILedService.h"

// java 라이브러리라고 생각해 보세요.

class javaLedService
{
	HMODULE h;
	ILedService* pLed;

public:
	javaLedService()
	{
		HMODULE h = LoadLibraryA("ledservice.dll");
		// linux : dlopen()

		typedef ILedService*(*F)();
		F f = (F)GetProcAddress(h, "CreateProxy");

		pLed = f();
	}

	~javaLedService()
	{
		delete pLed;
	}

	void LedOn()
	{
		//여기서 C++과 통신하기 위해서 JNI를 사용합니다.
		pLed->LedOn();
	}
};


// google에서 "adaptive autosar" 검색해서
// 7번째 pdf 찾아보세요
int main()
{
	javaLedService* p = new javaLedService;
	p->LedOn();
	delete p;
}