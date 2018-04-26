//1_EmptyClass5 - 73 page EBCO

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{

	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p1 = v.begin;
	auto p2 = s.begin;

	//반복자를 5카 전진하고 싶다.
	// +가 되는 반복자 : random_access_iterator
	// ++가, --가 되는 반복자 : bidirectional 
	p1 = p1 + 5;		// ok
	p2 = p2 + 5;		// error
	++++++++++p2;		// ok

	advance(p1, 5);
	advance(p2, 5);

}