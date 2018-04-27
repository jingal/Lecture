//client7
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
	static ProcessState& self()
	{
		static ProcessState instance;
		return instance;
	}
};

// binder ����̹����� ����� å������ Ŭ����
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

// Ư�� ������ ���� ��ȣ�� �����ϸ鼭 ����ϴ� Ŭ����
// Ư�� ���񽺿��� ����� å������.
class BpBinder
{
	int server;
public:
	BpBinder(int n) : server(n) {}

	// �ٽ� : ���� ��ȣ�� ���ڷ� ���� �ʿ� �����ϴ�.
	int transact(int code, int* msg, int* reply)
	{
		return IPCTreadState::self().transact(server, code, msg, reply);
	}
};

// ���ڷ� ���� �̸��� �޾Ƽ� BpBinder�� ��ȯ�ϴ� �Լ�
BpBinder* getService(const char* name)
{
	int reply;
	int server = IPCTreadState::self().transact(
		BINDER_SERVICE_MANAGER,
		SVC_MGR_CHECK_SERVICE,
		(int*)name,
		&reply);

	cout << "���� ��ȣ : " << server << endl;

	return new BpBinder(server);
}


// ������ ������ �̸��� ����(�Լ�)�� �����ϱ� ����
// �������̽��� �����մϴ�.
// �Ʒ� �������̽��� ����� �ۼ��ؼ� �������鶧�� ����ؾ� �մϴ�.
// 

struct ILedService
{
	virtual void LedOn() = 0;
	virtual void LedOff() = 0;
	virtual ~ILedService() {}
};


class BpLedService : public ILedService
{
	BpBinder* remote;

public:
	BpLedService() {
		remote = getService("LedService");
	}

	~BpLedService() {
		delete remote;
	}

	void LedOn()
	{
		int msg, reply;
		remote->transact(1, &msg, &reply);
	}

	void LedOff()
	{
		int msg, reply;
		remote->transact(2, &msg, &reply);
	}
};

int main()
{
	BpLedService* pLed = new BpLedService();

	pLed->LedOn();
	pLed->LedOff();

	delete pLed;
}