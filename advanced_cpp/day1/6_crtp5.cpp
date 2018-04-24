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
// Mouse�� 3�������� ����� �ϰ� �ʹ�.
class Mouse : public ObjectCount<Mouse, 3>
{

};

class Keyboard : public ObjectCount<Keyboard, 5>
{

};


int main()
{
	//objectCount�� 3���̻� ������ ���ϰ� �ϰ� �ʹ�.
	Mouse m[2];
	Keyboard k[2];
}