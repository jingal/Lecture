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

	//1. " ����ϰ� ���� �� -> �׳� ���
	//string s = R"(hello"world)";

	// 2. )" ����ϰ� ���� �� -> " ( ���̿� ����ڰ� ���ϴ� ��ū �߰� �ϸ� ��
	string s = R"***(hello)"world)***";

	cout << s << endl;
}
