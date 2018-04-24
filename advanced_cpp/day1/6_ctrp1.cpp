#include <iostream>
using namespace std;

//���̺귯�� ����
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

//����� Ŭ����
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