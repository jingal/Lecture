//6_ctrp2

#include <iostream>
using namespace std;

//���̺귯�� ����
class WindowBase
{
public:
	//��� �������� ������ �Լ�
	void onClick() {
		cout << "1 WindowBase onClick" << endl;
	}
};

// MS���̺귯���� WTL ���̺����� ����
template<typename T> struct Window : public WindowBase
{
	void msgLoop()		//msgLoop(Windows* const this)
	{
		//onClick();		//this -> onClick()
		static_cast<T*>(this)->onClick();
	}
};

//����� Ŭ����
struct MyWindow : public Window<MyWindow>
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