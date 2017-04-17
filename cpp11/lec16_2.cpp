#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	raw string literal
///////////////////////////////////////////////////////////////////////////

int main()
{
	//string s1 = "hello\n\\\\\\";

	//string s = R"(hello\n\t)";

	//1. " 출력하고 싶을 때 -> 그냥 출력
	//string s = R"(hello"world)";

	// 2. )" 출력하고 싶을 때 -> " ( 사이에 사용자가 원하는 토큰 추가 하면 됨
	string s = R"***(hello)"world)***";

	cout << s << endl;
}
