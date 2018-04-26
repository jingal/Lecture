// 6_callableobject9

#include <iostream>
using namespace std;

int main()
{
	int v1 = 10, v2 = 20;

	//[&](int a) { v1 = a; v2 = a; cout << "A" << endl; };
	// error, ()�����ڰ� ����Լ��̴�. ������� �ȵ�
	//[v1, v2](int a) { v1 = a, v2 = a, cout << "A" << endl; }(5);

	// mutable ���� : ()�����ڸ� �����Լ��� �ش޶�� �ǹ�
	// ���۷��� ĸ��
	[&v1, &v2](int a) { v1 = a, v2 = a, cout << "A" << endl; }(5);

	cout << v1 << endl;	//5������ �Ϸ��� �Ʒ��ڵ带 
						//��� �ؾ��ұ��?

	//------------------------------------------------------
	class ClosureType
	{
		int& v1;
		int& v2;
	public:
		ClosureType(int& a, int& b) : v1(a), v2(b) {}

		inline void operator()(int a) const
		{
			v1 = a, v2 = a;
			cout << "A" << endl;
		}
	};

	//ClosureType();			//�ӽð�ü ����
	ClosureType(v1, v2)(5);		//�ӽð�ü () ������ �Լ� ȣ��
}
