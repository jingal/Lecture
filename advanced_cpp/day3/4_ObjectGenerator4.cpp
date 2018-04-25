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
	//프로그램이 종료되기 전에 반드시 logging 하고 싶다.
	ScopedExit exit(&log);

	cout << "다른 코드" << endl;
}


