// 4_move - 133 page

#include <iostream>

using namespace std;


struct Test
{
	int* p = 0;

	Test() {
		p = new int[100];
	}

	Test(const Test& t)				// 복사 생성자
	{
		//깊은 복사
		cout << "복사 생성자" << endl;
		p = new int[100];
		memcpy(p, t.p, sizeof(int) * 100);
	}

	Test(Test&& t)			// move 생성
	{		
		// 소유권 이전
		cout << "move 생성자" << endl;
		p = t.p;		// 얕은 복사.
		t.p = 0;		// 원본 객체가 자원 포기
	}
	ㅁ

	~Test() { delete[] p; }
};

int main()
{
	Test t1;
	Test t2 = t1;	// 복사 생성자 호출
	Test t3 = std::move(t1);	// move 생성자 호출
}
