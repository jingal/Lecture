#include <iostream>
#include <vector>

using namespace std;


//�� �������� ����� ȣ���� �ʿ��Ѱ�?


int main()
{
	vector<int> v(10, 0);

	v.resize(7);				// �� ���� ��¥�� �޸𸮸� ���ϰ��ΰ�?

	cout << v.size() << endl;		//7
	cout << v.capacity() << endl;	//10

	vector<DBConnect> v2(10);	//DBConnect : �����ڿ��� DB�����Ѵ�.
	v2.resize(7);				// �̼��� �پ�� 3�� ��ü�� �޸𸮿��� �̽�.
								// ������ DB�� ������ �ݾƾ� �Ѵ�.
								// �Ҹ����� ����� ȣ���� �ʿ��ϴ�.

	v2.resize(8);				// �þ�� �ϳ��� ��ü�� ���� �޸𸮴� �̹� �ִ�.
								// �����ڸ� ȣ���ؼ� DB������ �ؾ��Ѵ�.
}
