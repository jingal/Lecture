//client9
#include <iostream>
#include <Windows.h>		//DLL load�Լ�

using namespace std;

// ���� �����ڿ��� 2���� ������ �����޾ƾ� �մϴ�.
// ILedService.h : �������̽� ���
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