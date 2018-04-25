// 2_typename3

#include <iostream>
#include <list>
using namespace std;


// 클래스 
// 1. 멤버 데이타
// 2. 멤버 함수
// 3. 멤버 타입 - value_type, size_type, iterator

int main()
{
	list<int> s = { 1,2,3 };
	//int sz = s.size();			// ?은 어떤 타입으로 할까

	//unsigned int sz = s.size();

	list<int>::size_type sz = s.size();
}