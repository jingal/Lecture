// 4_ObejctGennerator5 - 177 page

#include <iostream>
#include <functional>
using namespace std;


void log() { cout << "log" << endl; }
int goo() { cout << "goo" << endl; return 0; }

// ()�� ����ؼ� ȣ���� �� �ִ� �͵�
// 1. �Լ�
// 2. �Լ���ü
// 3. ���� ǥ����.. [] (int a) { return a + b; } (1,2)
// 4. ��� ����
// callable object : ()�� ȣ�Ⱑ���� ����

template<typename T>
class ScopedExit
{
	T handler;

public:
	ScopedExit(T f) : handler(f) {}
	~ScopedExit() { handler(); }
};


int main()
{	
	//���α׷��� ����Ǳ� ���� �ݵ�� logging �ϰ� �ʹ�.
	
	ScopedExit<void(*)()> exit1(&log);

	auto f = []() { cout << "bye" << endl; };
	ScopedExit< decltype(f) > exit2(f);
		
	cout << "�ٸ� �ڵ�" << endl;
}


