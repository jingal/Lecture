//client5
#include <iostream>
#include "io_ipc.h"

using namespace std;

// 드라이버를 오픈하고 드라이버 핸들을 관리하는 클래스
class ProcessState
{
public:
	const int mDriverFD;

private:
	ProcessState() : mDriverFD(binder_open(1024 * 128)) {}

public:
	static ProcessState& self()
	{
		static ProcessState instance;
		return instance;
	}
};

// binder 드라이버와의 통신을 책임지는 클래스
class IPCTreadState
{
public:
	int transact(int server, int code, int* msg, int* reply)
	{
		return binder_call(ProcessState::self().mDriverFD, msg, reply, server, code);
	}

private:
	IPCTreadState() {}

public:
	static IPCTreadState& self()
	{
		__declspec(thread) static IPCTreadState instance;
		return instance;
	}
};

// 특정 서비스의 서버 번호를 관리하면서 통신하는 클래스
// 특정 서비스와의 통신을 책임진다.
class BpBinder
{
	int server;
public:
	BpBinder(int n) : server(n) {}

	// 핵심 : 서버 번호를 인자로 받을 필요 없습니다.
	int transact(int code, int* msg, int* reply)
	{
		return IPCTreadState::self().transact(server, code, msg, reply);
	}
};

// 인자로 서비스 이름을 받아서 BpBinder를 반환하는 함수
BpBinder* getService(const char* name)
{	
	int reply;
	int server = IPCTreadState::self().transact(
		BINDER_SERVICE_MANAGER,
		SVC_MGR_CHECK_SERVICE,
		(int*)name,
		&reply);

	cout << "서버 번호 : " << server << endl;

	return new BpBinder(server);
}

int main()
{
	BpBinder* svc = getService("LedService");

	int msg, reply;

	svc->transact(1, &msg, &reply);
	svc->transact(2, &msg, &reply);

	delete svc;
}