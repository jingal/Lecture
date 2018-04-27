//client2
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



// 장점 : 시스템 어디에서도 드라이버 핸들이 필요하면 
//			ProcessState::self().mDriverFD
int main()
{
	ProcessState& proc = ProcessState::self();
	
	int reply;
	int server = binder_call(proc.mDriverFD,
		(int*)"LedService",
		&reply,
		BINDER_SERVICE_MANAGER,
		SVC_MGR_CHECK_SERVICE);

	cout << "서버 번호 : " << server << endl;
	
	int msg;
	binder_call(proc.mDriverFD, &msg, &reply, server, 1);
	binder_call(proc.mDriverFD, &msg, &reply, server, 2);	
}