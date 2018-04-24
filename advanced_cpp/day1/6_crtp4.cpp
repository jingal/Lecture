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
// Mouse�� 3�������� ����� �ϰ� �ʹ�.
class Mouse : public ObjectCount<Mouse>
{

};

class Keyboard : public ObjectCount<Keyboard>
{

};


int main()
{
	//objectCount�� 3���̻� ������ ���ϰ� �ϰ� �ʹ�.
	Mouse m[2];
	Keyboard k[2];
}