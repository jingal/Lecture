//client3
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
	// 오직 한개의 객체를 만들어서 반환하는 함수
	// 싱글톤 코드의 기본
	static ProcessState& self()
	{
		//실제 안드로이드에서는 new를 사용합니다.
		static ProcessState instance;
		return instance;
	}
};

// binder 드라이버와의 통신을 책임지는 클래스
class IPCTreadState
{
public:
	// binder_call과 비교해서 파라미터의 변화를 보세요.
	// 드라이버 핸들이 인자에 없습니다.
	// 인자의 중요도에 따라 순서 변경
	// 
	int transact(int server, int code, int* msg, int* reply)
	{
		//여기서 리눅스 시스템 프로그램으로 드라이버와 
		// 통신하는 코드를 만들어 놓았습니다. ioctl
		
		return binder_call(ProcessState::self().mDriverFD, msg, reply, server, code);
	}

private:
	IPCTreadState() {}

public:
	static IPCTreadState& self()
	{
		// 실제 안드로이드에서는 new를 사용하고
		// 포인터를 TSS(Thread Specific Storage)에
		// 보관해서 스레드당 한개 만들 수 있게 합니다.
		static IPCTreadState instance;
		return instance;
	}
};



// 장점 : 시스템 어디에서도 드라이버 핸들이 필요하면 
//			ProcessState::self().mDriverFD
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

	cout << "서버 번호 : " << server << endl;

	int msg;
	threadState.transact(server, 1, &msg, &reply);
	threadState.transact(server, 2, &msg, &reply);
}