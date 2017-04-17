#include <iostream>
#include <string>

using namespace std;


struct FLOAT
{
	float data;
	FLOAT(float f) //변환생성자
		: data(f) {}
};

//void foo(float) { cout << "float" << endl; }	//1.exactly matching
void foo(double) { cout << "double" << endl; }	//3. Promotion
void foo(int) { cout << "int" << endl; }		//4. standard conversion
void foo(FLOAT) { cout << "FLOAT" << endl; }	// 5. 사용자 정의 변환(연산자 생성자)
void foo(...) { cout << "..." << endl; }		// 6. 가변인자


template<typename T>
void foo(T a) { cout << "T" << endl; }			//2. 템플릿 버전을 사용해서 함수 생성.

int main()
{
	foo(3.4f);
}