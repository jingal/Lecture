#include <iostream>
#include <cassert>

using namespace std;


//#pragma pack(1)
struct Packet
{
	char cmd;
	int data;
};


static_assert(sizeof(Packet) == sizeof(char) + sizeof(int), "Error, unknown packet!!");


int main()
{
	cout << sizeof(Packet) << endl;	//8
}
