//client3
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

// binder ����̹����� ����� å������ Ŭ����
class IPCTreadState
{
public:
	// binder_call�� ���ؼ� �Ķ������ ��ȭ�� ������.
	// ����̹� �ڵ��� ���ڿ� �����ϴ�.
	// ������ �߿䵵�� ���� ���� ����
	// 
	int transact(int server, int code, int* msg, int* reply)
	{
		//���⼭ ������ �ý��� ���α׷����� ����̹��� 
		// ����ϴ� �ڵ带 ����� ���ҽ��ϴ�. ioctl
		
		return binder_call(ProcessState::self().mDriverFD, msg, reply, server, code);
	}

private:
	IPCTreadState() {}

public:
	static IPCTreadState& self()
	{
		// ���� �ȵ���̵忡���� new�� ����ϰ�
		// �����͸� TSS(Thread Specific Storage)��
		// �����ؼ� ������� �Ѱ� ���� �� �ְ� �մϴ�.
		static IPCTreadState instance;
		return instance;
	}
};



// ���� : �ý��� ��𿡼��� ����̹� �ڵ��� �ʿ��ϸ� 
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

	cout << "���� ��ȣ : " << server << endl;

	int msg;
	threadState.transact(server, 1, &msg, &reply);
	threadState.transact(server, 2, &msg, &reply);
}