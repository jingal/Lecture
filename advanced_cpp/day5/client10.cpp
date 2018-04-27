//client10
#include <iostream>
#include <Windows.h>		//DLL load�Լ�

using namespace std;

#include "ILedService.h"

// java ���̺귯����� ������ ������.

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
		//���⼭ C++�� ����ϱ� ���ؼ� JNI�� ����մϴ�.
		pLed->LedOn();
	}
};


// google���� "adaptive autosar" �˻��ؼ�
// 7��° pdf ã�ƺ�����
int main()
{
	javaLedService* p = new javaLedService;
	p->LedOn();
	delete p;
}