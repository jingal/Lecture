// VC�� �ϳ� �����ϰ�, "Server"��� ������Ʈ ���弼��

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
	//1. IPC�� ���� ���δ� ����̹� �����ϰ�,
	//	���� �޸� �Ҵ�.
	int fd = binder_open(1024 * 128);

	// 2. ���� �Ŵ��������
	int reply;
	binder_call(fd, //����̹� ��ȣ,
		(int*)"LedService", //
		&reply,
		BINDER_SERVICE_MANAGER, //���� ��ȣ(0)
		SVC_MGR_ADD_SERVICE);	//��� �ڵ�


								// 3. client ��û ��
	binder_loop(fd, handler);
}