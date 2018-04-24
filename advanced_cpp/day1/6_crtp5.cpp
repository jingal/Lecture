//6_ctrp5

#include <iostream>
using namespace std;

template<typename T, int N> class ObjectCount
{
	static int cnt;
public:

	ObjectCount() { if (++cnt > N) throw 1; }
	~ObjectCount() { --cnt; }

};
template<typename T, int N> int ObjectCount<T, N>::cnt = 0;

//-----------------------------------------------------------------
// Mouse도 3개가지만 만들게 하고 싶다.
class Mouse : public ObjectCount<Mouse, 3>
{

};

class Keyboard : public ObjectCount<Keyboard, 5>
{

};


int main()
{
	//objectCount를 3개이상 만들지 못하게 하고 싶다.
	Mouse m[2];
	Keyboard k[2];
}