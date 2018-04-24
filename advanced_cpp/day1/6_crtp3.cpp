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
	//objectCount를 3개이상 만들지 못하게 하고 싶다.
	ObjectCount m[4];
}