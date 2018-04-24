#include <iostream>
using namespace std;

//라이브러리 내부
struct Window
{
	void msgLoop()		//msgLoop(Windows* const this)
	{
		onClick();		//this -> onClick()
	}

	virtual void onClick() {
		cout << "1 Window onclick" << endl;
	}
};

//사용자 클래스
struct MyWindow: public Window
{
	void onClick() {
		cout << "2 MyWindow onclick" << endl;
	}
};

int main()
{
	MyWindow w;
	w.msgLoop();
}