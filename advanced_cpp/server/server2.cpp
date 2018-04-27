// VC샐 하나 실행하고, "Server"라는 프로젝트 만드세요

#include <iostream>
#include "io_ipc.h"
#include "ILedService.h"

using namespace std;


class LedService : public ILedService
{
public:
	void LedOn() {
		cout << "LedOn" << endl;
	}

	void LedOff() {
		cout << "LedOff" << endl;
	}
};

LedService service;

int handler(int code, int* msg, int* reply)
{
	switch (code)
	{
	case 1: service.LedOn(); break;
	case 2: service.LedOff(); break;
	}
	return 0;
}

int main()
{
	//1. IPC를 위한 바인더 드라이버 오픈하고,
	//	공유 메모리 할당.
	int fd = binder_open(1024 * 128);

	// 2. 서비스 매니저에등록
	int reply;
	binder_call(fd, //드라이버 번호,
		(int*)"LedService", //
		&reply,
		BINDER_SERVICE_MANAGER, //서비스 번호(0)
		SVC_MGR_ADD_SERVICE);	//명령 코드


								// 3. client 요청 댁
	binder_loop(fd, handler);
}