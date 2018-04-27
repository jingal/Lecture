//client2

#include <iostream>
#include "io_ipc.h"

using namespace std;


int main()
{
	//1. ����̹� ����
	int fd = binder_open(1024 * 128);

	//2. ���� �Ŵ������� ���� ��ȣ ��û
	int reply;
	int server = binder_call(fd, 
							(int*)"LedService",
							&reply,
							BINDER_SERVICE_MANAGER,
							SVC_MGR_CHECK_SERVICE);

	cout << "���� ��ȣ : " << server << endl;

	//3. ���� ������ ��û�� ������ �˴ϴ�.
	int msg;
	binder_call(fd, &msg, &reply, server, 1);
	binder_call(fd, &msg, &reply, server, 2);
}