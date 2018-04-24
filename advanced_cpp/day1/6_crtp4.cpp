//6_ctrp4

#include <iostream>
using namespace std;

template<typename T> class ObjectCount
{
	static int cnt;
public:

	ObjectCount() { if (++cnt > 3) throw 1; }
	~ObjectCount() { --cnt; }

};
template<typename T> int ObjectCount<T>::cnt = 0;

//-----------------------------------------------------------------
// Mouse도 3개가지만 만들게 하고 싶다.
class Mouse : public ObjectCount<Mouse>
{

};

class Keyboard : public ObjectCount<Keyboard>
{

};


int main()
{
	//objectCount를 3개이상 만들지 못하게 하고 싶다.
	Mouse m[2];
	Keyboard k[2];
}