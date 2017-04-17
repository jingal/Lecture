#include <iostream>
#include <string>

using namespace std;


struct FLOAT
{
	float data;
	FLOAT(float f) //��ȯ������
		: data(f) {}
};

//void foo(float) { cout << "float" << endl; }	//1.exactly matching
void foo(double) { cout << "double" << endl; }	//3. Promotion
void foo(int) { cout << "int" << endl; }		//4. standard conversion
void foo(FLOAT) { cout << "FLOAT" << endl; }	// 5. ����� ���� ��ȯ(������ ������)
void foo(...) { cout << "..." << endl; }		// 6. ��������


template<typename T>
void foo(T a) { cout << "T" << endl; }			//2. ���ø� ������ ����ؼ� �Լ� ����.

int main()
{
	foo(3.4f);
}