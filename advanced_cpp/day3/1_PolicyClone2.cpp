// 1_PolicyClone2 - 183 page

#include <iostream>
using namespace std;


//STL string
/*
template<typename T,
		typename Traits = char_traits<T>,
		typename Ax = allocator<T>>
class basic_string
{
	T* buff;
public:
	bool operator==(const basic_string& s)
	{
		return Traits::compare(buff, s.buff);
	}
};

typedef basic_string<char> string;
typedef basic_string<wchar_t> wstring;
*/

//string 클래스에 전달할 비교 정책을 담을 클래스
class ci_traits : public char_traits<char>
{
public:
	static bool compare(const char* s1, const char* s2, int sz)
	{
		return _memicmp(s1, s2, sz);
	}

	static bool eq(char c1, char c2)
	{
		return toupper(c1) == toupper(c2);
	}

	static bool lt(char c1, char c2)
	{
		return toupper(c1) < toupper(c2);
	}

	static bool gt(char c1, char c2)
	{
		return toupper(c1) > toupper(c2);
	}
};

typedef basic_string<char, ci_traits> ci_string;

int main()
{
	ci_string s1 = "abcd";
	ci_string s2 = "ABCD";

	if (s1 == s2)
		cout << "same" << endl;
	else
		cout << "not same" << endl;
}