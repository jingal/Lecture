#include <iostream>
#include <cstdio>

using namespace std;


class Test
{
	int value;

public:
	explicit Test(int n) : value(n) {}
};


int main()
{
	Test t1(5);			//	direct initialization ==> 인자 한개인 생성자를 호출해서 객체 초기화
	Test t2 = 5;		//	copy initialization ==> A. 5를 변환 생성자를 사용해서 Test 임시객체 생성
						//							B. 임시객체를 복사 생성자를 사용해서 t2 복사


	shared_ptr<int> p1(new int);		//ok..
	shared_ptr<int> p2 = new int;		// error.. shared_ptr<> 생성자는 explict, 
										// 요즘은 암시적 변환을 막자는 분위기이기 때문에, 대부분 explict 생성자를 사용
}