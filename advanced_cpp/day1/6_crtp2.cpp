//6_ctrp2

#include <iostream>
using namespace std;

//라이브러리 내부
class WindowBase
{
public:
	//모든 윈도우의 공통의 함수
	void onClick() {
		cout << "1 WindowBase onClick" << endl;
	}
};

// MS라이브러리중 WTL 라이블러리의 원리
template<typename T> struct Window : public WindowBase
{
	void msgLoop()		//msgLoop(Windows* const this)
	{
		//onClick();		//this -> onClick()
		static_cast<T*>(this)->onClick();
	}
};

//사용자 클래스
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