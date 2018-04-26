// 6_callableobject4

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// callable object : ()로 호출 가능한 객체
// 일반 함수 
// 함수 객체(Function Object, Functor)
// 람다 표현식
// 


void print(int n) {
	cout << n << ", ";
}


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

	//for_each(v.begin(), v.end(), s);	
	//-----------------------

	// C++11 : 람다 표현식
	// 함수가 사용되는 자리에 함수구현을
	// 전달하는 기술
	// [] : lambda introducer
	//		람다표현식이 시작됨을 알리는 것
	//
	//for_each(v.begin(), v.end(), 
	//	[](int n) { cout << n << ", "; });


	// f main함수의 지역변수입니다.
	// [사용하고 싶은 지역변수]...
	for_each(v.begin(), v.end(),
		[&f](int n) { f << n << ","; });
}
