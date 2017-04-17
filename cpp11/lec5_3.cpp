#include <iostream>
#include <cstdio>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	5�� ��ȯ�� Ư¡, �����, explicit
///////////////////////////////////////////////////////////////////////////

class File
{
	FILE* file;

public:

	//explicit ������ : �����ڸ� ���� �Ͻ��� ��ȯ�� ���´�. ����� ��ȯ ����..
	explicit File(const char* name, const char* mode = "wt")
	{
		file = fopen(name, mode);
	}
	
	~File() { fclose(file); }
	//������ ��� �Լ���..

	//��ȯ ������ �Լ� : File => FILE * ��ȯ ���
	operator FILE* () { return file; }
};


//������ ���� c�Լ�
//void foo(FILE* p) {}

void foo(File f) {}

int main()
{
	File f("a.txt");		
	//������ ���� c�Լ� ���

	//foo(f);		//File => FILE* �Ͻ��� ��ȯ �ʿ�...

	foo(f);
	foo(static_cast<File>("hello"));		//const char* => File ��ȯ�� �ǰ� �ִ�.

	//String s = "hello";
//	char s2[10];

//	strcpy(s2, s); // String => const char * �Ͻ��� ��ȯ ���
}