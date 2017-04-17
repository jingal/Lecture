#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	default / value initialization
///////////////////////////////////////////////////////////////////////////

class Point
{
public: 
	int x, y;

	//Point() {}						//����� default ������ �߰��ϰ� �ʱ�ȭ ���ϸ� �����Ⱚ
	Point() = default;
};

int main()
{
	Point p1;						// default initialization
	Point p2{};						// value initialization

	cout << p1.x << endl;			//�����Ⱚ
	cout << p2.x << endl;			// 0	
}
