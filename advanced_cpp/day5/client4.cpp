//client4
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
		static IPCTreadState instance;
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

	// 파라미터를 예측해 보세요
	// 핵심 : 서버 번호를 인자로 받을 필요 없습니다.
	int transact(int code, int* msg, int* reply)
	{
		// 구현해 보세요.
		return IPCTreadState::self().transact(server, code, msg, reply);
	}
};

int main()
{
	ProcessState& proc = ProcessState::self();
	IPCTreadState& threadState = IPCTreadState::self();


	int reply;
	int server = threadState.transact(
		BINDER_SERVICE_MANAGER,
		SVC_MGR_CHECK_SERVICE,
		(int*)"LedService",
		&reply);

	BpBinder* svc = new BpBinder(server);

	cout << "서버 번호 : " << server << endl;

	int msg;
	svc->transact(1, &msg, &reply);
	svc->transact(2, &msg, &reply);

	delete svc;
}