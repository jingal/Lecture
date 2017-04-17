#include <iostream>
#include <vector>

using namespace std;


//왜 생성자의 명시적 호출이 필요한가?


int main()
{
	vector<int> v(10, 0);

	v.resize(7);				// 이 순간 진짜로 메모리를 줄일것인가?

	cout << v.size() << endl;		//7
	cout << v.capacity() << endl;	//10

	vector<DBConnect> v2(10);	//DBConnect : 생성자에서 DB접속한다.
	v2.resize(7);				// 이순간 줄어들 3개 객체는 메모리에는 이싸.
								// 하지만 DB는 접속을 닫아야 한다.
								// 소멸자의 명시적 호출이 필요하다.

	v2.resize(8);				// 늘어나는 하나의 객체를 위한 메모리는 이미 있다.
								// 생성자를 호출해서 DB접속을 해야한다.
}
