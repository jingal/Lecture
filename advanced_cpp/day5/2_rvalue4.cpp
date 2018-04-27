//2_rvalue4

#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	Point() {}

	//복사 생성자를 정확히 파악해 봅시다.
	// 후보 1: 복사생성자를 호출하게 되므로 무한 복사 생성자 호출, 
	//			인자로 될 수 없다.
	//Point(Point p) {}

	//후보 2: 참조
	//단점 : 임시객체를 받을 수 없다.
	//			함수가 리턴하는값을 받을 수 없게 된다.
	//			임시객체에 대한 rvalue를 받아야 하기 때문에 탈락

	//Point(Point& p) {}
	//Point(Point p) {}		// Point p = p1; 또 복사생성자를 호출하게 되므로 무한 복사 생성자 호출


	//후보 3: 결국, lvalue와 rvalue를 모두 받으려면
	// const lvalue reference 밖에 없다.
	Point(const Point& p) { cout << "copy" << endl; }


	// rvalue 일때는 위의 함수가 아닌 아래 함수가 사용
	// 됩니다. 그래서 move생성자 모양이 아래와 같습니다.
	Point(Point&& p) { cout << "move" << endl; }
};


Point foo() { Point p; return p; }

int main()
{
	Point p1;
	Point p2(p1);		// Point( Point )의 모양이 필요합니다.

	Point p3 = foo();

	Point p4 = p1;								//copy
	Point p5 = static_cast<Point&&>(p1);		//move
	Point p6 = move(p2);						//move
}