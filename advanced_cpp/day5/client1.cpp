//client2

#include <iostream>
#include "io_ipc.h"

using namespace std;


int main()
{
	//1. 드라이버 오픈
	int fd = binder_open(1024 * 128);

	//2. 서비스 매니저에게 서비스 번호 요청
	int reply;
	int server = binder_call(fd, 
							(int*)"LedService",
							&reply,
							BINDER_SERVICE_MANAGER,
							SVC_MGR_CHECK_SERVICE);

	cout << "서버 번호 : " << server << endl;

	//3. 이제 서버에 요청을 보내면 됩니다.
	int msg;
	binder_call(fd, &msg, &reply, server, 1);
	binder_call(fd, &msg, &reply, server, 2);
}