// 6_callableobject3

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// callable object : ()로 호출 가능한 객체
// 일반 함수 
// 함수 객체(Function Object, Functor)
// 


void print(int n) {
	cout << n << ", ";
}


// 함수 객체의 장점
// 1. 다른 함수의 인자로 전달되어 사용될 때 inline 치환될 수 있다.
// 2. 상태를 가진함수를 만들 수 있다.
// 단점 : 모든 함수 객체는 다른 타입이므로 
//		foo(함수객체1), foo(함수객체2)는 각각 다른 foo 함수를 생성한다.
//		코드메모리가 커지는 단점이 있다.

struct Show
{
	ostream& os;
	string sep;

	Show(ostream& s = cout, string se = ",") : os(s), sep(se) {}
	void operator()(int n) const { os << n << sep; }
};

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	
	// 1 ~ 10까지를 차례대로 ? 함수에 보내달라.
	//for_each(v.begin(), v.end(), print);
	ofstream f("a.txt");
	Show s(f, "\t");

	for_each(v.begin(), v.end(), s);
	//for_each(v.begin(), v.end(), [](int a) { cout << a << ", "; });
}
