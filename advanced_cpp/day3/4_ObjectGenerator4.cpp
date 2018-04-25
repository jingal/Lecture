// 4_ObejctGennerator4 - 177 page

#include <iostream>
using namespace std;


void log() { cout << "log" << endl; }
int goo() { cout << "goo" << endl; return 0; }

class ScopedExit
{
	void(*handler)();

public:
	ScopedExit(void(*f)()) : handler(f) {}
	~ScopedExit() { handler(); }
};


int main()
{
	//���α׷��� ����Ǳ� ���� �ݵ�� logging �ϰ� �ʹ�.
	ScopedExit exit(&log);

	cout << "�ٸ� �ڵ�" << endl;
}


