//7_event

#include <iostream>
using namespace std;

// 단점 : 이벤트의 갯수 만큼 가상함수를 만들어야 함.
//			사용자 클래스에서 1~2개만 재정의해도
//			기반 클래스의 모든 가상함수 개수 만큼 테이블 생성.

struct Window
{
	void msgLoop()
	{
		//if(mouseClick == 1)
		onClick();
	}

	virtual void onClick() {}
};

struct MyWindow : public Window
{
	virtual void onClick() {}
};

int main()
{
	MyWindow w;
	w.msgLoop();
}