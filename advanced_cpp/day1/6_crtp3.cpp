//6_ctrp3

#include <iostream>
using namespace std;

class ObjectCount
{
	static int cnt;
public:

	ObjectCount() { if (++cnt > 3) throw 1; }
	~ObjectCount() { --cnt; }

};

int ObjectCount::cnt = 0;



int main()
{
	//objectCount�� 3���̻� ������ ���ϰ� �ϰ� �ʹ�.
	ObjectCount m[4];
}