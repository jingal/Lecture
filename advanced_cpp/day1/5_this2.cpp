//5_this

#include <iostream>
#include <vector>
using namespace std;

struct IBinder
{
	int binder;

	void f1() { cout << "f1" << endl; }
	int  f2() { cout << "f2" << endl; return 0; }
	int  f3() { cout << "f3" << endl; return binder; }

	//아래 함수는 왜 만들었을까요?
	int safe_f3() { return this ? f3() : 0; }
};


int main()
{
	//IBinder* p = new IBinder;
	IBinder* p = 0;
	p->f1();		//ok
	p->f2();		//ok
	//p->f3();		//error
	p->safe_f3();
}