// 6_callableobject3

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// callable object : ()�� ȣ�� ������ ��ü
// �Ϲ� �Լ� 
// �Լ� ��ü(Function Object, Functor)
// 


void print(int n) {
	cout << n << ", ";
}


// �Լ� ��ü�� ����
// 1. �ٸ� �Լ��� ���ڷ� ���޵Ǿ� ���� �� inline ġȯ�� �� �ִ�.
// 2. ���¸� �����Լ��� ���� �� �ִ�.
// ���� : ��� �Լ� ��ü�� �ٸ� Ÿ���̹Ƿ� 
//		foo(�Լ���ü1), foo(�Լ���ü2)�� ���� �ٸ� foo �Լ��� �����Ѵ�.
//		�ڵ�޸𸮰� Ŀ���� ������ �ִ�.

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

	for_each(v.begin(), v.end(), s);
	//for_each(v.begin(), v.end(), [](int a) { cout << a << ", "; });
}
