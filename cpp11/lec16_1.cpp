#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	user define literal
///////////////////////////////////////////////////////////////////////////

class Meter
{
	int value;
public:
	Meter(int n) : value(n) {}
};


// �������� ���ͷ��� �������� long long type���� �޾ƾ���
// char ������ ��� char* ���·�
Meter operator""_m(unsigned long long a)
{
	return Meter(static_cast<int>(a));
}

int main()
{
	//literal�� �������� ��Ȯ�ϰ� �˷��ֱ� ���ؼ� �߰�
	// _�� �߰��� ������ ǥ�ذ� �浹�� ���ϱ� ���ؼ�
	Meter m = 3_m;		//operator ""m(int a)

	float a = 3.4f;
	long b = 4l;


}
