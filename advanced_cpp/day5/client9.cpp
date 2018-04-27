//client9
#include <iostream>
#include <Windows.h>		//DLL load함수

using namespace std;

// 서버 제작자에세 2개의 파일을 제공받아야 합니다.
// ILedService.h : 인터페이스 헤더
// LedService.dll : proxy

#include "ILedService.h"

int main()
{
	HMODULE h = LoadLibraryA("ledservice.dll");
							// linux : dlopen()

	typedef ILedService*(*F)();
	F f = (F)GetProcAddress(h, "CreateProxy"); //dlsym()

	ILedService* p = f();

	p->LedOn();
	p->LedOff();

	delete p;
}