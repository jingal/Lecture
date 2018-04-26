// 3_ExceptionSafety6 - 197 page

#include <iostream>
#include <memory> 
using namespace std;

int foo() { return 1; }
void goo(shared_ptr<int> p, int n) {}

int main()
{
	//shared_ptr<int> p(new int);		//c++ ǥ�� ����Ʈ ������

	// ����Ʈ ������ ���� Raw Pointer�� 2�� �̻���
	// ����Ʈ �����Ϳ� ������ �ȵȴ�.
	//int* p1 = new int;
	//shared_ptr<int> sp1(p1);
	//shared_ptr<int> sp2(p1);

	// RAII�� �ؾ��Ѵ�. ��, sp�� ���鶧 new
	shared_ptr<int> sp1(new int);

	// shared_ptr�� ���� ����������.
	// �Ʒ� �ڵ��� �������� ?
	// �Ʒ��� ������ ����Ǵ� ��쵵 ���� �� �ֽ��ϴ�.
	// 1. new int ����
	// 2. foo ȣ�� => ���⼭ ���ܰ� ���´ٸ�
	// 3. shared_ptr �����
	// 4. goo ȣ��

	//goo(shared_ptr<int>(new int), foo());

	// make_shared<int>() : int �޸𸮸� �Ҵ��ϰ� 
	//						�����ϴ� shared_ptr�� ����� �޶�.
	shared_ptr<int> sp3 = make_shared<int>();
	goo(make_shared<int>(), foo());
}