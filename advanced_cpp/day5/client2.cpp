//client2
#include <iostream>
#include "io_ipc.h"

using namespace std;

// ����̹��� �����ϰ� ����̹� �ڵ��� �����ϴ� Ŭ����
class ProcessState
{
public:
	const int mDriverFD;

private:
	ProcessState() : mDriverFD(binder_open(1024 * 128)) {}

public:
	// ���� �Ѱ��� ��ü�� ���� ��ȯ�ϴ� �Լ�
	// �̱��� �ڵ��� �⺻
	static ProcessState& self()
	{
		//���� �ȵ���̵忡���� new�� ����մϴ�.
		static ProcessState instance;	
		return instance;
	}
};



// ���� : �ý��� ��𿡼��� ����̹� �ڵ��� �ʿ��ϸ� 
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

	cout << "���� ��ȣ : " << server << endl;
	
	int msg;
	binder_call(proc.mDriverFD, &msg, &reply, server, 1);
	binder_call(proc.mDriverFD, &msg, &reply, server, 2);	
}