// 6_callableobject4

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// callable object : ()�� ȣ�� ������ ��ü
// �Ϲ� �Լ� 
// �Լ� ��ü(Function Object, Functor)
// ���� ǥ����
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

	// 1 ~ 10������ ���ʴ�� ? �Լ��� �����޶�.
	//for_each(v.begin(), v.end(), print);
	ofstream f("a.txt");
	Show s(f, "\t");

	//for_each(v.begin(), v.end(), s);	
	//-----------------------

	// C++11 : ���� ǥ����
	// �Լ��� ���Ǵ� �ڸ��� �Լ�������
	// �����ϴ� ���
	// [] : lambda introducer
	//		����ǥ������ ���۵��� �˸��� ��
	//
	//for_each(v.begin(), v.end(), 
	//	[](int n) { cout << n << ", "; });


	// f main�Լ��� ���������Դϴ�.
	// [����ϰ� ���� ��������]...
	for_each(v.begin(), v.end(),
		[&f](int n) { f << n << ","; });
}
