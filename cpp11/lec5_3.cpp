#include <iostream>
#include <cstdio>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	5강 변환의 특징, 장단점, explicit
///////////////////////////////////////////////////////////////////////////

class File
{
	FILE* file;

public:

	//explicit 생성자 : 생성자를 통한 암시적 변환을 막는다. 명시적 변환 가능..
	explicit File(const char* name, const char* mode = "wt")
	{
		file = fopen(name, mode);
	}
	
	~File() { fclose(file); }
	//수많은 멤버 함수들..

	//변환 연산자 함수 : File => FILE * 변환 허용
	operator FILE* () { return file; }
};


//예전에 만든 c함수
//void foo(FILE* p) {}

void foo(File f) {}

int main()
{
	File f("a.txt");		
	//예전에 만든 c함수 사용

	//foo(f);		//File => FILE* 암시적 변환 필요...

	foo(f);
	foo(static_cast<File>("hello"));		//const char* => File 변환이 되고 있다.

	//String s = "hello";
//	char s2[10];

//	strcpy(s2, s); // String => const char * 암시적 변환 허용
}